/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true*/

    int binsearch(vector<int>& nums, int target, int l, int h) {
        int mid = l + ((h-l)/2);
        if (l>h) return -1;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) return binsearch(nums,target,l,mid-1);
        else return binsearch(nums,target,mid+1,h);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while (i >=0 && i<m && j>=0 && j<n) {
            if (target == matrix[i][j]) return true;
            if (target < matrix[i][j]) {
                if (binsearch(matrix[i],target,0,n-1) == -1) {
                    return false;
                } else return true;
            }
            else {
                i++;
            }
        }
        return false;
    }
