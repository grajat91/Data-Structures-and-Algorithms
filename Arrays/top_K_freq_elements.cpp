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
        priority_queue<pair<int,int>> pq;
        
        for (int i=0;i<nums.size();i++) {
            freq_elem[nums[i]]++;
        }
        
        for (auto it : freq_elem) {
            pq.push(make_pair(it.second,it.first));
        }
        
        for (int i=0;i<k;i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
