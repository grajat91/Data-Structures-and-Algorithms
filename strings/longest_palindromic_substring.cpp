/*Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.*/

    string longestPalindrome(string s) {
        int l,r;
        string res = "";
        for (int i=0;i<s.length();i++) {
            
            l = i;
            r = i;
            while (l>=0 && r < s.length()) {
                if (s[r] == s[l]) {
                    if (res.length() < r-l+1) {
                        res = s.substr(l,r-l+1);
                    }
                } else break;
                l--;
                r++;
            }
            
            l = i;
            r = i+1;
            while (l>=0 && r < s.length()) {
                if (s[r] == s[l]) {
                    if (res.length() < r-l+1) {
                        res = s.substr(l,r-l+1);
                    }
                } else break;
                l--;
                r++;
            }
        }
        return res;
    }
