/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
*/
    int majorityElement(vector<int>& nums) {
        int majority_element = nums[0];
        int count = 1;
        
        for (int i=1;i<nums.size();i++) {
            if (count == 0) {
                count++;
                majority_element = nums[i];
            } else if (nums[i] == majority_element) count++;
            else count --;
        }
        return majority_element;
    }
