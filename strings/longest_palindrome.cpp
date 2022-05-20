/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/

    int longestPalindrome(string s) {
        int charcount[256] = {0};
        int result = 0;
        bool flag = false;
        for (int i=0;i<s.length();i++) {
            charcount[s[i]]++;
        }
        for (int i=0;i<256;i++) {
            if (charcount[i] % 2 == 0) {
                result+=charcount[i];
            } else if (charcount[i]%2 != 0) {
                if (!flag) {
                    result+=charcount[i];
                    flag = true;
                } else result+=charcount[i]-1;
                
            }
        }
        return result;
    }
