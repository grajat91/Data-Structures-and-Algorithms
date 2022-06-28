/*Given two strings s and t, return the number of distinct subsequences of s which equals t.
A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
*/

    int numDistinct_util(string s, string t, int i, int j) {
        if (j == 0) return 1;
        if (i == 0) return 0;
        if (s[i-1] == t[j-1]) return numDistinct_util(s,t,i-1,j-1)+numDistinct_util(s,t,i-1,j);
        return numDistinct_util(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        return numDistinct_util(s,t,s.length(),t.length());
    }
