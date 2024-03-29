/*Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.*/

    long long maxSubarraySum(int arr[], int n){
        
        int max_ending = arr[0];
        int result = arr[0];
        for (int i=1; i<n; i++) {
            max_ending = max(max_ending+arr[i],arr[i]);
            result = max(result,max_ending);
        }
        return result;
    }
