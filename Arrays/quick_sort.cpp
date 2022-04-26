/*Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position low and its ending position high.
Implement the partition() and quickSort() functions to sort the array.

Example 1:
Input: 
N = 5 
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9*/

void quickSort(int arr[], int low, int high)
    {
        int partitionindex;
        if (low < high) {
            partitionindex = partition(arr,low,high);
            quickSort(arr,low,partitionindex-1);
            quickSort(arr,partitionindex+1,high);
        }
    }
  
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];
        int partitionindex = low;
        for (int i=low;i<high;i++) {
            if (arr[i]<=pivot) {
                swap(arr[i],arr[partitionindex]);
                partitionindex++;
            }
        }
        swap(arr[partitionindex],arr[high]);
        return partitionindex;
    }
