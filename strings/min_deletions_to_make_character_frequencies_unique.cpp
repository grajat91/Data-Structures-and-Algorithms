/*A string s is called good if there are no two different characters in s that have the same frequency.
Given a string s, return the minimum number of characters you need to delete to make s good.
The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

Example 1:
Input: s = "aab"
Output: 0
Explanation: s is already good.

Example 2:
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".

Example 3:
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).*/

    int minDeletions(string s) {
        vector<int> char_count(26,0);
        for (char c : s) char_count[c-'a']++;
        sort(char_count.begin(),char_count.end());
        
        int min_deletions=0;
        for (int i=24;i>=0;i--) {
            if (char_count[i] == 0) break;
            if (char_count[i] >= char_count[i+1]) {
                int prev = char_count[i];
                char_count[i] = max(0,char_count[i+1]-1);
                min_deletions += prev - char_count[i];
            }
        }
        return min_deletions;
    }
