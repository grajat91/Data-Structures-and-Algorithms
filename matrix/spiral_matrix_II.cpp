/*Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.


Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
 */

    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n;
        int top = 0;
        int bottom = n;
        int count = 1;
        vector<vector<int>> matrix(n,vector<int>(n,0));
        while (left < right && top < bottom) {
            for (int i=left;i<right;i++) {
                matrix[top][i] = count;
                count++;
            }
            top++;
            //cout<<"Reached here1\n";
            for (int i=top;i<bottom;i++) {
                matrix[i][right-1] = count;
                count++;
            }
            right--;
            //cout<<"Reached here2\n";
            if (!(left < right && top < bottom)) break;
        
            for (int i=right-1;i>=left;i--) {
                matrix[bottom-1][i] = count;
                count++;
            }
            bottom--;
            //cout<<"Reached here3\n";
            for (int i=bottom-1;i>=top;i--) {
                matrix[i][left] = count;
                count++;
            }
            left++;
            //cout<<"Reached here4\n";
        }
        return matrix;
    }
