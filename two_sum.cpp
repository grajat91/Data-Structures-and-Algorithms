//Question - Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> pos;
        //int presum=0;
        //int n = nums.size();
        for (int i=0;i<nums.size();i++) {
            int diff = target - nums[i];
            if (pos.find(diff) != pos.end()) {
                res.push_back(pos[diff]);
                res.push_back(i);
            } else {
                pos[nums[i]] = i;
            }
        }
        return res;
    }
};
