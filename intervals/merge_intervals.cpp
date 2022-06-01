/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/

    struct sort_pred {
        		bool operator()(const vector<int> &left, const vector<int> &right) {
            			return left[0] < right[0];
        		}
    	};

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), sort_pred());
        int m = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i=1;i<m;i++) {
            if (intervals[i][0] > end) {
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start,end});
        return result;
    }
