/*Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

Example 1:
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Example 2:
Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.*/

//Queue based solution
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int>> diagonal;
        diagonal.push({m-1,0});
        while (!diagonal.empty()) {
            int size = diagonal.size();
            int x = diagonal.front().first;
            int y = diagonal.front().second;
            int val = matrix[x][y];
            for (int i=0; i<size;i++) {
                if (matrix[diagonal.front().first][diagonal.front().second] !=  val) return false;
                int x = diagonal.front().first - 1;
                if (isvalid(x,diagonal.front().second,m,n) && (x != diagonal.back().first || diagonal.front().second != diagonal.back().second)) diagonal.push({x,diagonal.front().second});
                int y = diagonal.front().second + 1;
                if (isvalid(diagonal.front().first,y,m,n) && (y != diagonal.back().second || diagonal.front().first != diagonal.back().first)) diagonal.push({diagonal.front().first,y});
                diagonal.pop();
            }
            
        }
        return true;
    }

// Solution without queue
    bool isvalid(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if (matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        return true;
    }
