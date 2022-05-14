/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]*/

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_elem;
        vector<int> result;
        
        for (int i=0;i<nums.size();i++) {
            freq_elem[nums[i]]++;
        }
        
        int size = nums.size();
        vector<int> A[size+1];
        
        for (auto it : freq_elem) {
            A[it.second].push_back(it.first);
        }
        
        int count = 0;
        for (int i=size;i>=0;i--) {
            if (A[i].size() > 0) {
                if (count < k) {
                    for (auto it : A[i]) {
                        result.push_back(it);
                        count++;
                    }
                } 
            }
        }
    
        return result;
    }
