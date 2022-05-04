/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false*/

    bool cmparrays(int arr1[26], int arr2[26]) {
        for (int i=0;i<26;i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int counts1[26] = {0};
        int counts2[26] = {0};
        if (s1==s2) return true;
        int s1len = s1.length();
        for (char c : s1) counts1[c-'a']++;
        int start = 0;
        int end = s1.length()-1;
        string t = s2.substr(start,s1.length());
        for (char c : t) counts2[c-'a']++;
        while(end<s2.length()) {
            if (cmparrays(counts1,counts2)) return true;
            else {
                end++;
                if (end !=s2.length()) counts2[s2[end]-'a']++;
                counts2[s2[start]-'a']--;
                start++;
            }
        }
        return false;
    }
