/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false*/

    bool isvalid(int m, int n, int x, int y) {
        return ((x>=0 && x < m) && (y>=0 && y < n));
    }
    
    bool DFSrec(vector<vector<char>>& board, string word, int x, int y, int index, int m, int n) {
        if (index == word.length()) return true;
        if (!isvalid(m,n,x,y) || board[x][y] != word[index]) return false;
        board[x][y] = '0';
        bool status = DFSrec(board,word,x-1,y,index+1,m,n) || DFSrec(board,word,x+1,y,index+1,m,n) || DFSrec(board,word,x,y-1,index+1,m,n) || DFSrec(board,word,x,y+1,index+1,m,n);
        board[x][y] = word[index];
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if(board[i][j] == word[0] && DFSrec(board,word,i,j,0,m,n)) {
                    return true;
                }
            }
        }
        return false;
    }
