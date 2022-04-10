/*You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.*/

int missingNumber(int arr[], int n) 
{ 
  bool arr1[n+1] = {false};
  int ans;
  for (int i=0; i<n; i++) {
    if ((arr[i]>0) && (arr[i]<=n)) {
      arr1[arr[i]] = 1;
    }
  }
        
  for (int i=0; i<n+1; i++) {
    if ((i!=0) && (arr1[i]!=1)) {
      return i;
    }
  }
  return n+1;
} 
