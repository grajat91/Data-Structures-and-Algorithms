//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            sum = max(nums[i],nums[i]+sum);
            if (sum>maxsum) {
                maxsum = sum;
            }
        }
        return maxsum;
    }
