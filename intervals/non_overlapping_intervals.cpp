/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.*/

    struct sort_pred {
        bool operator()(const vector<int> &left, const vector<int> &right) {
            return left[0] < right[0];
        }
    };
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sort_pred());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int total_non_overlap_intervals=0;
        for (int i=1;i<intervals.size();i++) {
            if (intervals[i][0] >= end) {
                start = intervals[i][0];
                end = intervals[i][1];
            } else if (start <= intervals[i][0] && end >= intervals[i][1]) {
                total_non_overlap_intervals++;
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                total_non_overlap_intervals++;
            }
        }
        return total_non_overlap_intervals;
    }
