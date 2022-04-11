/*An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
Given an array arr[] of size N, find the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 
Input:
N = 3
arr[] = {1,2,3}
Output: 2
Explanation: index 2 is 3.
It is the peak element as it is 
greater than its neighbour 2.
*/

int peakElement(int arr[], int n)
{
   int low = 0;
   int high = n-1;
   int mid;
   
   while (low<=high) {
       mid = (low+high)/2;
       
       if (((mid==n-1) || (arr[mid]>=arr[mid+1])) && ((mid==0) || (arr[mid-1]<=arr[mid]))) {
            return mid;
       } 
       if (arr[mid-1] > arr[mid]) {
           high = mid -1;
       } else {
           low = mid + 1;
       }
   }
   return mid;
}
