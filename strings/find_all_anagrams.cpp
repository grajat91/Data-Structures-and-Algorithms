/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".*/

    bool compare_arr(int arr1[], int arr2[]) {
        for (int i=0;i<26;i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int countp[26] = {0};
        int counts[26] = {0};
        
        if (s.length() < p.length()) return result;
        for (int i=0;i<p.length();i++) countp[p[i] - 'a']++;
        
        int begin=0;
        int end=p.length()-1;
        for (int i=begin;i<=end;i++) counts[s[i]-'a']++;
        while(end < s.length()) {
            if (compare_arr(countp, counts)) result.push_back(begin);
            counts[s[begin]-'a']--;
            begin++;
            end++;
            if (end != s.length()) counts[s[end]-'a']++;
        }
        return result;
    }
