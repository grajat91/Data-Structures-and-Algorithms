/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.*/

    int rob_util(vector<int>& nums, int begin, int end) {
        int prev1 = nums[begin];
        int prev2 = 0;
        for (int i=begin+1;i<end;i++) {
            int curr = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int rob_minus_house1 = rob_util(nums,1,nums.size());
        int rob_minus_lasthouse = rob_util(nums,0,nums.size()-1);
        return max(rob_minus_house1,rob_minus_lasthouse);
    }
