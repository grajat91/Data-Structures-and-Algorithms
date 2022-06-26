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
