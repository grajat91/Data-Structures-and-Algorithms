/*Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.*/

    bool isvalid(int x, int y, int m, int n) {
        return ( x >= 0 && x <= m-1 && y >= 0 && y <= n-1);
    }
    
    bool isboundary(int x, int y, int m, int n) {
        return ( x == 0 || x == m-1 || y == 0 || y == n-1);
    }
    
    void DFSrec(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int m, int n) {
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        visited[x][y] = true;
        for (int k=0;k<4;k++) {
            if(isvalid(x+dx[k], y+dy[k], m, n) && board[x+dx[k]][y+dy[k]] == 'O' && !visited[x+dx[k]][y+dy[k]]) {
                DFSrec(board, visited, x+dx[k], y+dy[k],m,n);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,true));
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                visited[i][j] = false;
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (board[i][j] == 'O' && visited[i][j] == false) {
                    if (isboundary(i,j,m,n)) {
                        DFSrec(board,visited,i,j,m,n);
                    }
                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0;j<n; j++) {
                if (board[i][j] == 'O' && visited[i][j] == false) board[i][j] = 'X';
            }
        }
    }
