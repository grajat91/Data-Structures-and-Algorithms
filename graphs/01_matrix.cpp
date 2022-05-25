/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

    bool isvalid(int m, int n, int x, int y) {
        return (x>=0 && y>=0 && x< m && y < n);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        vector<vector<int>> result(m,vector<int>(n,-1));
        queue<pair<int,int>> bfsq; 
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    bfsq.push({i,j});
                }
            }
        }
        
        while (!bfsq.empty()) {
            int x = bfsq.front().first;
            int y = bfsq.front().second;
            bfsq.pop();
            for (int k=0;k<4;k++) {
                if (isvalid(m,n,x+dx[k],y+dy[k]) && result[x+dx[k]][y+dy[k]] == -1) {
                    bfsq.push({x+dx[k], y+dy[k]});
                    result[x+dx[k]][y+dy[k]] = result[x][y] + 1;
                }
            }
        }
        
        return result;
    }
