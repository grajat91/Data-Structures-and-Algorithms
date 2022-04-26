/*Given two sorted arrays of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.
If there are even number of elements in the resulting array, find the floor of the average of two medians.

Example 1:

Input:
N = 5, M = 6 
arr[] = {1,2,3,4,5}
brr[] = {3,4,5,6,7,8}
Output: 4
Explanation: After merging two arrays, 
elements will be as 1 2 3 3 4 4 5 5 6 7 8
So, median is 4.*/

int findMedian(int arr[], int n, int brr[], int m)
    {
        int i=0;
        int j=0;
        int k=0;
        //int arr[] = {1,2,3,4,5};
        //int brr[] = {3,4,5,6,7};
        //int N=5;
        //int M=5;
        int crr[n+m];
        int median;
        while (i<n || j<m) {
            if (arr[i] <= brr[j]) {
                crr[k] = arr[i];
                k++;
                i++;
            } else {
                crr[k] = brr[j];
                k++;
                j++;
            }
        }
        //for (int i=0;i<10;i++) {
          //  cout << crr[i] <<",";
        //}
    //cout << endl;
        if ((n+m)%2 == 0) {
            int l = ((n+m)/2);
            median = (crr[l]+crr[l-1])/2;
        } else {
            int l = ((m+n)/2);
            //cout <<l<<endl;
            median = crr[l];
        }
        //cout << median << endl;
        return median;
    }
