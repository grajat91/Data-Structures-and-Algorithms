/*Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4*/

    bool isvalid(int x, int y, int m, int n) {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total_time = 0;
        queue<pair<int,int>> bfsq;
      
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 2) {
                    bfsq.push({i,j});
                }
            }
        }
      
        bfsq.push({-1,-1});
        while (bfsq.empty() == false) {
            int x = bfsq.front().first;
            int y = bfsq.front().second;
            if ((x == -1 && y == -1) && bfsq.size() > 1) {
                total_time++;
                bfsq.push({-1,-1});
            } else if ((x == -1 && y == -1) && bfsq.size() == 1) {
                break;
            }
            else {
                for (int k=0; k<4; k++) {
                    if (isvalid(x+dx[k],y+dy[k],m,n) && grid[x+dx[k]][y+dy[k]] == 1) {
                        grid[x+dx[k]][y+dy[k]] = 2;
                        bfsq.push({x+dx[k],y+dy[k]});
                    }
                }
            }
            bfsq.pop();
        }
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return total_time;
    }
