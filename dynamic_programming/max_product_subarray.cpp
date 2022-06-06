/*Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/

    int maxProduct(vector<int>& nums) {
        
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];
        int choice1, choice2;
        for (int i=1;i<nums.size();i++) {
            choice1 = nums[i]*maxProduct;
            choice2 = nums[i]*minProduct;
            maxProduct = max(nums[i],max(choice1, choice2));
            minProduct = min(nums[i],min(choice1, choice2));
            result = max(result,maxProduct);
        }
        return result;
    }
