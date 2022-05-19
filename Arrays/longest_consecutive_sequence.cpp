/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9*/

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> lcs;
        int max_lcs = INT_MIN;
        
        for (int i=0;i<nums.size();i++) {
            lcs.insert(nums[i]);
        }
        
        for (int i=0;i<nums.size();i++) {
            int count=0;
            if (lcs.find(nums[i]-1) == lcs.end()) {
                int x = nums[i];
                while(lcs.find(x) != lcs.end()) {
                    count+=1;
                    x+=1;
                }
                max_lcs = max(max_lcs,count);
            }
        }
        return max_lcs;
    
