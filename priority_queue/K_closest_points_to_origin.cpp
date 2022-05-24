/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].*/

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<float,int>> pq;
        
        for (int i=0;i<points.size();i++) {
            float euc_dis = sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
            pq.push({euc_dis,i});
        }
        
        for (int i=0;i<points.size()-k;i++) {
            pq.pop();
        }
        
        while (pq.size()) {
            int i = pq.top().second;
            result.push_back(points[i]);
            pq.pop();
        }
        
        return result;
    }
