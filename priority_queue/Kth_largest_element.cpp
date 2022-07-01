/*Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4*/

    int findKthLargest(vector<int>& nums, int k) {
        
        if (nums.size()==1) return nums[0];
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (auto num : nums) {
            min_heap.push(num);
            if (min_heap.size() > k) min_heap.pop();
        }
        return min_heap.top();
    }
