/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1*/

    bool isvalid (int x, int y, int m, int n) {
        return ((x>=0 && x<m) && (y>=0 && y< n));
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numislands = 0;
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
                if (!visited[i][j] && grid[i][j] == '1') {
                    //cout<<"Increasing number of islands\n";
                    numislands++;
                    visited[i][j] = 1;
                    //cout<<"Starting from element "<<i<<","<<j<<endl;
                    bfsq.push({i,j});
                    while (bfsq.empty() == false) {
                        int x = bfsq.front().first;
                        int y = bfsq.front().second;
                        bfsq.pop();
                        for (int k=0;k<4;k++) {
                            bool valid = isvalid(x+dx[k],y+dy[k],m,n);
                            if (isvalid(x+dx[k],y+dy[k],m,n) && (!visited[x+dx[k]][y+dy[k]]) && (grid[x+dx[k]][y+dy[k]] == '1')) {
                                //cout<<"Moving to element "<<x+dx[k]<<","<<y+dy[k]<<" which is valid="<<valid<<endl;
                                visited[x+dx[k]][y+dy[k]] = 1;
                                bfsq.push({x+dx[k],y+dy[k]});
                            }
                        }
                    } 
                }
            }
        }
        return numislands;
    }
