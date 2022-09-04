/*Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Constraints:

2 <= n <= 9
0 <= k <= 9*/

//BFS based solution:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        queue<int> bfsq;
        for (int i=1;i<=9;i++) bfsq.push(i);
        
        while (!bfsq.empty()) {
            int front_elem = bfsq.front();
            bfsq.pop();
            if (to_string(front_elem).size()==n) {
                if (result.size() == 0) result.push_back(front_elem);
                else if (result.back() != front_elem) result.push_back(front_elem);
                
            }
            if (to_string(front_elem).size() > n) break;
            if (to_string(front_elem).size() < n) {
                if ((front_elem%10)-k>=0 && (front_elem%10)-k<=9) {
                    bfsq.push(front_elem*10 + ((front_elem%10)-k));
                }
                if ((front_elem%10)+k<10) {
                    bfsq.push(front_elem*10 + ((front_elem%10)+k));
                    
                }
            }
        }
        return result;
    }

//DFS based solution
