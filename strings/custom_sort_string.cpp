/*You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.

Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
Example 2:

Input: order = "cbafg", s = "abcd"
Output: "cbad"*/

    string customSortString(string order, string s) {
        string result;
        unordered_map<char,int> s_frequency;
        for (char c : s) s_frequency[c]++;
        
        for (char c : order) {
            while (s_frequency[c] != 0) {
                result+=c;
                s_frequency[c]--;
            }
        }
        
        for (auto it : s_frequency) {
            while (it.second != 0) {
                result+=it.first;
                it.second--;
            }
        }
        return result;
    }
