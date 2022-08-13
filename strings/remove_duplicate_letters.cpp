/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 */
 
     string removeDuplicateLetters(string s) {
        vector<bool> isseen(26,false);
        vector<int> freq(26,0);
        for (int i=0;i<s.size();i++) {
            freq[s[i]-'a']++;
        }
        stack<int> st;
        string result;
        for (int i=0;i<s.size();i++) {
            freq[s[i]-'a']--;
            if (isseen[s[i]-'a']) {
                continue;
            }
            while (!st.empty() && s[st.top()] > s[i] && freq[s[st.top()]-'a'] > 0) {
                isseen[s[st.top()]-'a'] = false;
                st.pop();
            }
            st.push(i);
            isseen[s[i]-'a'] = true;
        }
        while (!st.empty()) {
            result+=s[st.top()];
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
