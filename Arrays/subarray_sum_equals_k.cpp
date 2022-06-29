/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2*/

    int subarraySum(vector<int>& nums, int k) {
        int result=0;
        unordered_map<int,int> prefix_sum;
        int curr_sum=0;
        prefix_sum[curr_sum]++;
        
        for (int i=0;i<nums.size();i++) {
            curr_sum += nums[i];
            if (prefix_sum.find(curr_sum - k) != prefix_sum.end()) {
                result += prefix_sum[curr_sum-k];
            }
            prefix_sum[curr_sum]++;
        }
        return result;
    }
