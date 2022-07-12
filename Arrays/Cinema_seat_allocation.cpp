/*A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.
Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.
Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.

Example 1:
Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
Output: 4
Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.

Example 2:
Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
Output: 2

Example 3:
Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
Output: 4*/

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int result = 0;
        unordered_map<int,vector<int>> row_state;
        
        for (auto it : reservedSeats) {
            //if (it[1] == 1 || it[0] == 10) continue;
            row_state[it[0]].push_back(it[1]);
        }
        result = (n-row_state.size())*2;
        
        for (auto it : row_state) {
            bool flag = false;
            vector<bool> reserved(11,0);
            for (int x : it.second) reserved[x] = 1;
            
            if (!reserved[2] && !reserved[3] && !reserved[4] && !reserved[5]) {
                result++;
                flag = true;
            }
            if (!reserved[6] && !reserved[7] && !reserved[8] && !reserved[9]) {
                result++;
                flag = true;
            }
            if (!flag && (!reserved[4] && !reserved[5] && !reserved[6] && !reserved[7])) {
                result++;
            }
        }
        return result;
    }
