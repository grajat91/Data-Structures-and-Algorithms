/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]*/

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prodminusself(n,1);
        int prod = nums[0];
        for (int i=1;i<nums.size();i++) {
            prodminusself[i] = prod;
            prod *= nums[i];
        }
        prod = nums[n-1];
        for (int i=n-2;i>=0;i--) {
            prodminusself[i] = prodminusself[i]*prod;
            prod = prod * nums[i];
        }
        return prodminusself;
    }
