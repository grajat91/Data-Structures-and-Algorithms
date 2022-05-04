/*You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0*/

    bool isvalid (int x, int y, int m, int n) {
        return ((x>=0 && x<m) && (y>=0 && y< n));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = INT_MIN;
        int current_area=0;
        queue<pair<int,int>> bfsq;
        int visited[m][n];
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                visited[i][j] = 0;
            }
        }
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                current_area=0;
                if (!visited[i][j] && grid[i][j] == 1) {
                    current_area++;
                    visited[i][j] = 1;
                    bfsq.push({i,j});
                    while (bfsq.empty() == false) {
                        int x = bfsq.front().first;
                        int y = bfsq.front().second;
                        bfsq.pop();
                        for (int k=0;k<4;k++) {
                            bool valid = isvalid(x+dx[k],y+dy[k],m,n);
                            if (isvalid(x+dx[k],y+dy[k],m,n) && (!visited[x+dx[k]][y+dy[k]]) && (grid[x+dx[k]][y+dy[k]] == 1)) {
                                visited[x+dx[k]][y+dy[k]] = 1;
                                bfsq.push({x+dx[k],y+dy[k]});
                                current_area++;
                            }
                        }
                    }
                }
                max_area=max(max_area,current_area);   
            }
        }
        return max_area;
    }
