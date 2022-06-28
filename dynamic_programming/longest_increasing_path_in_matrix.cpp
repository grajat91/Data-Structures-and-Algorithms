/*Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.*/

class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isvalid(int x, int y, int m, int n) {
        return (x>=0 && y>=0 && x < m && y < n);
    }
    int DFSRec(vector<vector<int>>& matrix, vector<vector<int>>& visited, int x, int y, int m, int n) {
        if (visited[x][y] != 0) return visited[x][y];
        visited[x][y] = 1;
        for (int k=0;k<4;k++) {
            if (isvalid(x+dx[k], y+dy[k], m, n) && matrix[x+dx[k]][y+dy[k]] > matrix[x][y]) {
                visited[x][y] = max(visited[x][y], 1 + DFSRec(matrix, visited, x+dx[k], y+dy[k], m,n));
            }
        }
        return visited[x][y];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (visited[i][j] == 0) {
                    visited[i][j] = DFSRec(matrix, visited, i, j, m, n);
                }
            }
        }
        int longest_path = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                longest_path = max(longest_path, visited[i][j]);
            }
        }
        return longest_path;
    }
};
