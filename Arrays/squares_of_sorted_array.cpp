/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]*/

    vector<int> sortedSquares(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        vector<int> result(r+1,0);
        int i=r;
        while (l<=r) {
            if (abs(nums[l]) >= abs(nums[r])) {
                result[i] = nums[l]*nums[l];
                l++;
                i--;
            } else {
                result[i] = nums[r]*nums[r];
                r--;
                i--;
            }
        }
        return result;
    }
