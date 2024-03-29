/*Given an Integer N and a list arr. Sort the array using bubble sort algorithm.
Example 1:

Input: 
N = 5
arr[] = {4, 1, 3, 9, 7}
Output: 
1 3 4 7 9*/

void bubbleSort(int arr[], int n)
{
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1-i;j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
