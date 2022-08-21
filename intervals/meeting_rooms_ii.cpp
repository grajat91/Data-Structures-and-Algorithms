/*Description
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.)

Contact me on wechat to get Amazon、Google requent Interview questions . (wechat id : jiuzhang0607)


(0,8),(8,10) is not conflict at 8

Example
Example1

Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)
Example2

Input: intervals = [(2,7)]
Output: 1
Explanation: 
Only need one meeting room*/

int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        // min heap to track min end time of merged intervals
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // compare curr start w/ earliest end time, if no overlap then pop
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            // add new room (will replace/be same size if above was true)
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
