/*Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/

    bool canPartition(vector<int>& nums) {
        
        int array_sum = accumulate(nums.begin(), nums.end(),0);
        if (array_sum % 2 != 0) return false;
        
        int target_sum = array_sum/2;
        int n = nums.size();
        bool dpsum[target_sum + 1][n+1];
        
        for (int i=0;i<=n;i++) dpsum[0][i] = true;
        for (int i=1;i<=target_sum;i++) dpsum[i][0] = false;
        
        for (int i=1;i<=target_sum;i++) {
            for (int j=1;j<=n;j++) {
                dpsum[i][j] = dpsum[i][j-1];
                if (i >= nums[j-1]) {
                    dpsum[i][j] = (dpsum[i][j-1]) || (dpsum[i-nums[j-1]][j-1]);
                }
            }
        }
        return dpsum[target_sum][n];
    }
