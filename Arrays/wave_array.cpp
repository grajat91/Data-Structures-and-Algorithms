/*Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
If there are multiple solutions, find the lexicographically smallest one.
Input:
n = 5
arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
Explanation: Array elements after 
sorting it in wave form are 
2 1 4 3 5. */

void convertToWave(vector<int>& arr, int n){
  if (arr[0]<arr[1]) {
    swap(arr[0],arr[1]);
  }
  for (int i=1; i<n-1; i++) {
    if ((arr[i]<arr[i-1]) && (arr[i]<arr[i+1])) {
      continue;
    }
    else {
      swap(arr[i],arr[i+1]);
    }
  }
}
