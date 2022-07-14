/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.\
Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 */

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int> result;
        int l=0;
        int r=0;
        int n = nums.size();
        while (r < n) {
            while (!q.empty() && nums[q.back()] < nums[r]) q.pop_back();
            q.push_back(r);
            if (l > q.front()) q.pop_front();
            if (r+1 >= k) {
                result.push_back(nums[q.front()]);
                l+=1;
            }
            r+=1;
        }
        return result;
    }
