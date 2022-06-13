/*Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]*/

    void subsets_util(vector<int>& nums, int i, vector<int> temp, vector<vector<int>>& all_subsets) {
        if (i == nums.size()) {
            all_subsets.push_back(temp);
            return;
        }
        subsets_util(nums,i+1,temp,all_subsets);
        temp.push_back(nums[i]);
        subsets_util(nums,i+1,temp,all_subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all_subsets;
        vector<int> temp;
        subsets_util(nums,0,temp,all_subsets);
        return all_subsets;
    }
