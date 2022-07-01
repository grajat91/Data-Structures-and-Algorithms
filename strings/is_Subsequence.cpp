/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false*/

    bool isSubsequence_util(string s, string t, int m, int n) {
        if (m==0) return true;
        if (n==0) return false;
        if (s[m-1] == t[n-1]) return isSubsequence_util(s,t,m-1,n-1);
        else return isSubsequence_util(s,t,m,n-1);
    }
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length()) return false;
        return isSubsequence_util(s,t,s.length(),t.length());
    }
