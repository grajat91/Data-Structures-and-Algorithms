/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.*/

    string minWindow(string s, string t) {
        vector<int> count(256,0);
        int needed = t.size();
        int begin = 0;
        int end = 0;
        int minstart = 0;
        int minlength = INT_MAX;
        for (char c : t) count[c]++;
        while (end < s.size()) {
            if (count[s[end]] > 0) needed--;
            count[s[end]]--;
            end++;
            while(needed == 0) {
                if (end - begin < minlength) {
                    minlength = end-begin;
                    minstart = begin;
                }
                count[s[begin]]++;
                if (count[s[begin]] > 0) needed++;
                begin++;
            }
        }
        return minlength == INT_MAX?"":s.substr(minstart,minlength);
    }
