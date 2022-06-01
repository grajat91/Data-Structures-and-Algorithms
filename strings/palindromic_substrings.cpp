/*Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".*/

    int countSubstrings(string s) {
        int l,r;
        int num_of_pls = 0;;
        for (int i=0;i<s.length();i++) {
            
            l = i;
            r = i;
            while (l>=0 && r < s.length()) {
                if (s[r] == s[l]) {
                    num_of_pls++;
                } else break;
                l--;
                r++;
            }
            
            l = i;
            r = i+1;
            while (l>=0 && r < s.length()) {
                if (s[r] == s[l]) {
                    num_of_pls++;
                } else break;
                l--;
                r++;
            }
        }
        return num_of_pls;
    }
