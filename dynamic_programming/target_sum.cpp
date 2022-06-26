/*You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1*/

//Recursion based approach

    int findTargetSumWays_util(vector<int>& nums, int target, int n) {
        if (n == 0 && target == 0) return 1;
        if (n == 0 && target != 0) return 0;
        
        return findTargetSumWays_util(nums, target-nums[n-1], n-1) + findTargetSumWays_util(nums, target+nums[n-1], n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = findTargetSumWays_util(nums, target, n);
        return result;
    }

//DP based solution
/*let us say we have the array as [1,1,1,1,1] and the target = 3;
We just need to add (+ or -) signs in front of the integers.

e.g +1 +1 +1 -1 -1 = 3

Essentially, what we are doing is that we are just splitting the numbers into two subsets, one with positive signs and the other with negative signs

(1 , 1 , 1) => with positive signs
(1 , 1) => with negative signs

and we are calculating the difference of the sum of these two sets
(1 , 1 , 1) => with positive signs , sum = 3
(1 , 1) => with negative signs , sum = 2

diff = target = (3-2) = 1

So we just need to find all such pairs of subsets whose sum difference is equal to our given target.

Consider S1 and S2 to be one such pair then the following equations holds

S1 - S2 = target
S1 + S2 = sum of all the elements

By simplifing the above 2 equations we get, 2* S1 = target + Sum of all the elements

=> S1 = (target + Sum of all the elements) / 2

So, this problem now reduces to just finding count of subsets which are having sum equal to S1.*/

    int findTargetSumWays_util(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n+1][target+1];
        for (int i=0;i<=n;i++) dp[i][0] = 1;
        for (int j=1;j<=target;j++) dp[0][j] = 0;
        
        for (int i=1;i<=n;i++) {
            for (int j=0;j<=target;j++) {
                if (nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum_of_vector = 0;
        for (int x : nums) sum_of_vector+=x;
        int final_target_sum = (sum_of_vector + target)/2;
        if (abs(target) > sum_of_vector) return 0;
        if ((sum_of_vector + target) %2 != 0) return 0;
        return findTargetSumWays_util(nums, final_target_sum);
    }
