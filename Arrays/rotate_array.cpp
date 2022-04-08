/*Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer. 
Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.*/

void rotateArr(int arr[], int d, int n) {
  reverse(arr,arr+d);
  reverse(arr+d,arr+n);
  reverse(arr,arr+n);
}
