/*You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.

In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.

For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
place stamp at index 0 of s to obtain "abc??",
place stamp at index 1 of s to obtain "?abc?", or
place stamp at index 2 of s to obtain "??abc".
Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
We want to convert s to target using at most 10 * target.length turns.

Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.

 

Example 1:

Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.
Example 2:

Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".*/

    bool compare_strings(string stamp, string target, string t) {
        if (target == t) return false;
        for (int i=0;i<target.size();i++) {
            if (target[i] == '?') continue;
            else {
                if (target[i] != stamp[i]) return false;
                
            }
        }
        return true;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        int len_stamp = stamp.size();
        int len_target = target.size();
        vector<int> result;
        string t;
        for (int i=0;i<len_stamp;i++) t+='?';
        string s;
        for (int i=0;i<target.size();i++) s+='?';
        bool status = true;
        while (target != s && status) {
            status = false;
            for (int i=0;i<=len_target-len_stamp;i++) {
                string target_sub = target.substr(i,len_stamp);
                if (compare_strings(stamp,target_sub,t)) {
                    status = true;
                    result.push_back(i);
                    for (int j=i;j< i + len_stamp;j++) target[j] = '?';
                }
            }
        }
        
        if (target != s) {
            vector<int> answer;
            return answer;
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
