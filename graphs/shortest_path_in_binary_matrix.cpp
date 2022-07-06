/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1*/

    bool isvalid(int x, int y, int m, int n) {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> bfsq;
        int dx[8] = {-1,1,0,0,-1,-1,1,1};
        int dy[8] = {0,0,-1,1,-1,1,-1,1};
        
        bfsq.push({0,0});
        grid[0][0] = 1;
        while(!bfsq.empty()) {
            int x = bfsq.front().first;
            int y = bfsq.front().second;
            bfsq.pop();
            if (x == m-1 &&  y == n-1) return grid[x][y];
            for (int k=0;k<8;k++) {
                if (isvalid(x+dx[k],y+dy[k],m,n) && grid[x+dx[k]][y+dy[k]] == 0) {
                    grid[x+dx[k]][y+dy[k]] = grid[x][y] + 1;
                    bfsq.push({x+dx[k],y+dy[k]});
                }
            }
        }
        return -1;
    }
