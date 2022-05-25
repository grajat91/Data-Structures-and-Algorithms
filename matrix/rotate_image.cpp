/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]*/

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i=0;
        //Transpose the matrix
        while (i < n) {
            for (int j=i;j<n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
            i++;
        }
        //Reverse the matrix
        for (int i=0;i<n;i++) {
            for (int j=0;j<(n/2);j++) {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }