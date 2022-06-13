/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]*/

    void permute_util(vector<int>& nums, int l, int r, vector<vector<int>>& all_permutations) {
        if (l == r) {
            all_permutations.push_back(nums);
            return;
        } else {
            for (int i=l;i<=r;i++) {
                swap(nums[i], nums[l]);
                permute_util(nums,l+1,r,all_permutations);
                swap(nums[i], nums[l]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all_permutations;
        permute_util(nums, 0, nums.size()-1, all_permutations);
        return all_permutations;
    }
