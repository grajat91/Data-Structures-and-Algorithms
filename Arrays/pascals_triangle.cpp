/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
*/

    vector<vector<int>> generate(int numRows) {
        
        if (numRows == 1) {
            vector<vector<int>> result;
            result.push_back({1});
            return result;
        }
        if (numRows == 2) {
            vector<vector<int>> result;
            result.push_back({1});
            result.push_back({1,1});
            return result;
        }
        vector<vector<int>> result;
        result.push_back({1});
        result.push_back({1,1});
        for (int i=2;i<numRows;i++) {
            vector<int> subres;
            subres.push_back(result[i-1][0]);
            int n = result[i-1].size();
            for (int j=0;j<n-1;j++) {
                subres.push_back(result[i-1][j]+result[i-1][j+1]);
            }
            subres.push_back(result[i-1][n-1]);
            result.push_back(subres);
            subres.clear();
        }
        return result;
    }
