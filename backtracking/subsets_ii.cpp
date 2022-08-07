/*Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10*/

    void subsets_util(vector<int>& nums, int i, vector<int> temp, vector<vector<int>>& all_subsets) {
        if (i==nums.size()) {
            all_subsets.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subsets_util(nums,i+1,temp,all_subsets);
        temp.pop_back();
        while (i+1 < nums.size() && nums[i]==nums[i+1]) i+=1;
        subsets_util(nums,i+1,temp,all_subsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        vector<vector<int>> all_subsets;
        vector<int> temp;
        subsets_util(nums,0,temp,all_subsets);
        return all_subsets;
    }
