/*Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.


Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.*/

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        int size = words.size(); 
        map<string, int> word_freq;
        for (string word : words) word_freq[word]++;
        vector<string> A[size+1];
        for (auto it:word_freq) {
            A[it.second].push_back(it.first);
        }
        
        for (int i=size;i>=0;i--) {
            if (!A[i].empty()) {
                for (auto it : A[i]) {
                    if (k > 0) {
                        result.push_back(it);
                    }
                    k--;
                    if (k==0) break;
                }
            }
        }
        return result;
    }
