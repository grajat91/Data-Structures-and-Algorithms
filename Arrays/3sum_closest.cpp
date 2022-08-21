/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
 
Constraints:
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104*/


    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i=0;i<n-2;i++) {
            int l = i+1;
            int r = n-1;
            while (l<r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum-target) < diff) {
                    diff = abs(sum-target);
                    result = sum;
                }
                if (sum > target) r--;
                else if (sum < target) l++;
                else return sum;
            }
        }
        return result;
    }
