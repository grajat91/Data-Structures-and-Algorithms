/*Description
You are given a m x n 2D grid initialized with these three possible values.
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

Example1
Input:
[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output:
[[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

Explanation:
the 2D grid is:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
the answer is:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
  
Example2
Input:
[[0,-1],[2147483647,2147483647]]
Output:
[[0,-1],[1,2]]*/

    void wallsAndGates(vector<vector<int>> &rooms) {

        int m = rooms.size();
        int n = rooms[0].size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        queue<pair<int, int>> bfsq;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (rooms[i][j] == 0) {
                    bfsq.push({i,j});
                }
            }
        }

        while (!bfsq.empty()) {
            int x = bfsq.front().first;
            int y = bfsq.front().second;
            int distance = rooms[x][y];
            bfsq.pop();
            for (int k=0;k<4;k++) {
                if (isvalid(x+dx[k], y+dy[k], m, n) && (rooms[x+dx[k]][y+dy[k]] == 2147483647)) {
                    //distance++;
                    bfsq.push({x+dx[k],y+dy[k]});
                    rooms[x+dx[k]][y+dy[k]] = distance+1;
                }
            }
        }
    }
