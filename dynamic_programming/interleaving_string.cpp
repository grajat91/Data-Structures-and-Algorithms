/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false*/

//Recursion code
    bool isInterleave_util(string s1, string s2, string s3, int i, int j, int k) {
        if (i == 0 && j == 0 && k == 0) return true;
        else if (k == 0) return false;
        else if (i > 0 && s3[k-1] == s1[i-1] && j > 0 && s3[k-1] == s2[j-1]) return (isInterleave_util(s1,s2,s3,i-1,j,k-1) || isInterleave_util(s1,s2,s3,i,j-1,k-1));
        else if (i > 0 && s3[k-1] == s1[i-1]) return isInterleave_util(s1,s2,s3,i-1,j,k-1);
        else if (j > 0 && s3[k-1] == s2[j-1]) return isInterleave_util(s1,s2,s3,i,j-1,k-1);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length()) return false;
        return isInterleave_util(s1,s2,s3,s1.length(), s2.length(), s3.length());
    }

//DP Solution
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length()) return false;
        int m = s1.length();
        int n = s2.length();
        bool dp_table[m+1][n+1];
        dp_table[0][0] = true;
        for (int i=0;i<=m;i++) {
            for (int j=0;j<=n;j++) {
                if (i==0 && j==0) dp_table[i][j] = true;
                else if (i==0) dp_table[i][j] = dp_table[i][j-1] && s2[j-1] == s3[i+j-1];
                else if (j==0) dp_table[i][j] = dp_table[i-1][j] && s1[i-1] == s3[i+j-1];
                else dp_table[i][j] = (dp_table[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp_table[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return dp_table[m][n];
    }
