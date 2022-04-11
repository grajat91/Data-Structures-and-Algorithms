/*Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).
Input:
N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less 
than 0 is found. So output 
is "-1".*/

int findFloor(long long int arr[], int N, long long int K) {
    
    int low = 0;
    int high = N-1;
    int mid;
    int ans;
    if (K<arr[0]) {
        return -1;
    }
    
    while (low <=high) {
        mid = low + (high-low)/2;
        if (arr[mid] > K) {
            high = mid-1;
        } else {
            if (arr[mid] < K) {
                low = mid+1;
                ans = mid;
            } else {
                return mid;
            }
        }
    }
    return ans;
    
}
