/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]*/

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> oneresult;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-2;i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] == 0) {
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                  //Code to avoid duplicates in the solution
                    while(j+1<k && nums[j] == nums[j+1]) j++;
                    while(j<k-1 && nums[k] == nums[k-1]) k--;
                }
                if (nums[j] + nums[k] + nums[i] > 0) k--;
                else j++;
            }
        }
        return result;
    }
