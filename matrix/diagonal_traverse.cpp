/*Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]*/

//Using unordered_map
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        unordered_map<int,vector<int>> diagonal_store;
        bool up_to_down = false;
        int s = m+n-2;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                diagonal_store[i+j].push_back(mat[i][j]);
            }
        }
        
        for (int i=0;i<=s;i++) {
            if (!up_to_down) {
                for (int j=diagonal_store[i].size()-1;j>=0;j--) {
                    result.push_back(diagonal_store[i][j]);
                }
                up_to_down = true;
            } else {
                for (auto c : diagonal_store[i]) result.push_back(c);
                up_to_down = false;
            }    
        }
        return result;
    }
