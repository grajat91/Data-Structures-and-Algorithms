/*Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int top = 0;
        int bottom = matrix.size();
        int right = matrix[0].size();
        vector<int> spiral_matrix;
        
        while (left < right && top < bottom) {
            for (int i=left;i<right;i++) {
                spiral_matrix.push_back(matrix[top][i]);
            }

            top++;
            
            for (int i=top;i<bottom;i++) {
                spiral_matrix.push_back(matrix[i][right-1]);
            }
            
            right--;
            if (!(left < right && top < bottom)) break;
            
            for (int i=right-1;i>=left;i--) {
                spiral_matrix.push_back(matrix[bottom-1][i]);
            }
           
            bottom--;
            
            for (int i=bottom-1;i>=top;i--) {
                spiral_matrix.push_back(matrix[i][left]);
            }
            
            left++;
        }
        return spiral_matrix;
    }
