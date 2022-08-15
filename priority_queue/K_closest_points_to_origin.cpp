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

// Priority Queue Solution
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

//Quick sort partition function
    bool operator_compare (const vector<int> &left, const vector<int> &right) {
        return (left[0]*left[0])+(left[1]*left[1]) <= (right[0]*right[0])+(right[1]*right[1]);
    }
    

    void quickselect_partition(vector<vector<int>>& points, int k, int left, int right) {
        vector<int> pivot = points[right];
        int pindex = left;
        for (int i=left;i<right;i++) {
            if (operator_compare(points[i],pivot)) {
                swap(points[i],points[pindex]);
                pindex++;
            }
        }
        swap(points[right],points[pindex]);
        if (pindex == k) return;
        else if (pindex > k)  quickselect_partition(points,k,left,pindex-1);
        else quickselect_partition(points,k, pindex+1, right);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        int n = points.size();
        if (k == n) return points;
        quickselect_partition(points,k,0,n-1);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
