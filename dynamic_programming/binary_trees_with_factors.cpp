/*Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.
Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

Example 1:
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].*/

    int numFactoredBinaryTrees(vector<int>& nums) {
	    unordered_map< int,long> numtrees;
        long mod = pow(10, 9) + 7;
	    int  n = nums.size();
	    sort(nums.begin(),nums.end());
        
	    for (int i=0;i<n;i++) {
		    numtrees[nums[i]]=1;
		    for (int j=0;j<i;j++) {
			    if (nums[i]%nums[j] == 0) {
				    if (numtrees.find(nums[i]/nums[j]) != numtrees.end()) {
				        numtrees[nums[i]] = numtrees[nums[i]] + (numtrees[nums[j]]*numtrees[(nums[i]/nums[j])])%mod;
					}
			    }
		    }
	    }
	int total_trees=0;
    
	for (auto it : nums) {
		total_trees = (total_trees + numtrees[it])%mod;
	    }
		return total_trees;
    }
