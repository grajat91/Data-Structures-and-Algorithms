/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4*/

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> height_stack;
        int res = 0;
        for (int i=0;i<n;i++) {
            while (!height_stack.empty() && heights[height_stack.top()] >= heights[i]) {
                int curr = height_stack.top();
                height_stack.pop();
                int curr_area = heights[curr]*(height_stack.empty() ? i : (i - height_stack.top() - 1));
                res = max(res,curr_area);
            }
            height_stack.push(i);
        }
        
        while(!height_stack.empty()) {
            int curr = height_stack.top();
            height_stack.pop();
            int curr_area = heights[curr]*(height_stack.empty() ? n : (n - height_stack.top() - 1));
            res = max(res,curr_area);
        }
        return res;
    }
