/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

    int longestOnes(vector<int>& nums, int k) {
        //i is the left of the sliding window
        int i=0;
        //j is the right of the sliding window
        int j=0;
        while (j<nums.size()) {
            //If we encounter a 0, while increasing our window, i.e. j -> decrease k
            if (nums[j] == 0) k--;
            //If k becomes 0, then we need to move left of our window i.e. i. While decreasing window size, if nums[i] == 0, increase k again because we are throwing that 0 out of the window.
            if (k<0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }
            j++;
        }
        return j-i;
    }
