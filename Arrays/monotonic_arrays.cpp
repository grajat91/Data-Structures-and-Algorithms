/*An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false*/

    bool isMonotonic(vector<int>& nums) {
        int neg_changes=0;
        int pos_changes=0;
        int zero_changes=0;
        
        for (int i=1;i<nums.size();i++) {
            if (nums[i]-nums[i-1]>0) pos_changes++;
            if (nums[i]-nums[i-1]<0) neg_changes++;
            else zero_changes++;
        }
        if (pos_changes==0 || neg_changes==0) return true;
        return false;
    }
