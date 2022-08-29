/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.*/

//RECURSION SOLUTION
    bool wordBreak_util(string s, unordered_set<string> wordset) {
        int n = s.size();
        if (n==0) return true;
        for (int i=0;i<n;i++) {
            if ((wordset.find(s.substr(0,i+1)) != wordset.end()) && wordBreak_util(s.substr(i+1),wordset)) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordset;
        for (auto word : wordDict) wordset.insert(word);
        int n = s.size();
        //return wordBreak_util(s,wordset);
    }

//DYNAMIC PROGRAMMING SOLUTION
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset;
        int n = s.length();
        for (int i=0;i<wordDict.size();i++) wordset.insert(wordDict[i]);
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i=1;i<=n;i++) {
            for (int j=0;j<i;j++) {
                if (dp[j] && (wordset.find(s.substr(j,i-j)) != wordset.end())) {
                    dp[i] = true;
                    break;
                }
            }
        }
        //for (int i=0;i<=n;i++) cout<<dp[i]<<" ";
        return dp[n];
    }
