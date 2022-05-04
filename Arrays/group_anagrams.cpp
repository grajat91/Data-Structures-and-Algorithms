/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]Given an array of strings strs, group the anagrams together. You can return the answer in any order.*/

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //int count[26] = {0};
        unordered_map<string,vector<string>> anamap;
        vector<vector<string>> result;
        for (auto s : strs) {
            int count[26] = {0};
            for (char c : s) {
                count[c-'a']++;
            }
            string t="";
            for (int i=0;i<26;i++) {
                t=t+string(count[i],i+'a');
            }
            anamap[t].push_back(s);
        }
        
        for (auto p : anamap) {
            result.push_back(p.second);
        }
        return result;
    }
