/*Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 

Example 1:

Input: n = 5, arr[] = {0, -1, 2, -3, 1}
Output: 1
Explanation: 0, -1 and 1 forms a triplet
with sum equal to 0.*/

bool findTriplets(int arr[], int n)
    { 
        int j,k;
        int sum=0;
        sort(arr,arr+n);
        for (int i=0;i<n-1;i++) {
            j = i+1;
            k = n-1;
            while (j<k) {
                sum = arr[i]+arr[j]+arr[k];
                if (sum == 0) {
                    return true;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return false;
    }
