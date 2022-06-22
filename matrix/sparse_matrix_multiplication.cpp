/*Given two Sparse Matrix A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.

Example1

Input: 
[[1,0,0],[-1,0,3]]
[[7,0,0],[0,0,0],[0,0,1]]

Output:
[[7,0,0],[-7,0,3]]

Explanation:
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |*/

    vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {

        vector<vector<int>> result (a.size(), vector<int> (b[0].size(), 0));
        unordered_map<int,vector<pair<int, int>>> matrix_a_map;
        unordered_map<int,vector<pair<int, int>>> matrix_b_map;

        for (int i=0;i<a.size();i++) {
            for (int j=0;j<a[0].size();j++) {
                if (a[i][j] != 0) matrix_a_map[j].push_back(make_pair(i,a[i][j]));
            }
        }

        for (int i=0;i<b.size();i++) {
            for (int j=0;j<b[0].size();j++) {
                if (b[i][j] != 0) matrix_b_map[i].push_back(make_pair(j,b[i][j]));
            }
        }
        for (auto elema : matrix_a_map) {
            for (auto elemb :  matrix_b_map) {
                if (elema.first == elemb.first) {
                    for (auto pa : elema.second) {
                        for (auto pb : elemb.second) {
                            result[pa.first][pb.first] += (pa.second*pb.second);
                        }
                    }
                }
            }
        }
        return result;
    }
