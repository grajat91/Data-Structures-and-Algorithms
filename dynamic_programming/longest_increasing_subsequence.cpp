/*Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.*/

    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for (int i=0;i<nums.size();i++) {
            auto it = lower_bound(result.begin(), result.end(), nums[i]);
            if (it == result.end()) result.push_back(nums[i]);
            else *it = nums[i];
        }
        return result.size();
    }
