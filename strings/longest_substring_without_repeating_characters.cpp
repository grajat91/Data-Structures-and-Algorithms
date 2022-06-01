/*Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int count[256] = {0};
        int longest_substr_len = 0;
        while (l <= r && r < s.length()) {
            if (count[s[r]] > 0) {
                count[s[l]]--;
                l++;
            } else {
                count[s[r]]++;
                longest_substr_len = max(longest_substr_len,(r-l+1));
                r++;
            }
            //cout<<l<<" "<<r<<" "<<count[97]<<" "<<count[98]<<" "<<count[99]<<endl;
        }
        return longest_substr_len;
    }
