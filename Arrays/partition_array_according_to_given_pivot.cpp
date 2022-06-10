/*You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.

Example 1:
Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
*/

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l=0;
        int n = nums.size();
        int result[n];
        int mid = 0;
        int last_pivot_occ;
        while (mid<=h) {
                if (nums[mid] < pivot) {
                    swap(nums[l], nums[mid]);
                    l++;
                    mid++;
                }
                 else if (nums[mid] == pivot) {
                    mid++;
                }
                else if (nums[mid] > pivot) {
                    swap(nums[mid], nums[h]);
                    h--;
                }
        }
        
        return nums;
    }
