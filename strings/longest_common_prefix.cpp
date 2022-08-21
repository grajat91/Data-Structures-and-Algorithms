/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string prefix;
        for (int j=0;j<strs[0].size();j++) {
            int count=1;
            for (int i=1;i<strs.size();i++) {
                if (strs[i][j] == strs[0][j]) {
                    count++;
                }
            }
            if (count == strs.size()) prefix+=strs[0][j];
            else break;
        }
        return prefix;
    }
