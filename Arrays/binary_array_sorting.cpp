/*Given a binary array A[] of size N. The task is to arrange the array in increasing order.
Note: The binary array contains only 0  and 1.
 

Example 1:

Input: 
5
1 0 1 1 0

Output: 
0 0 1 1 1

Explanation: 
After arranging the elements in 
increasing order, elements will be as 
0 0 1 1 1.*/

void binSort(int A[], int N)
    {
        int start = 0;
        int end = N-1;
        while (start<=end)
        {
            if (A[start] == 1 && A[end] == 0) 
            {
                swap(A[start], A[end]);
                start++;
                end--;
            }
            if (A[start] == 0) start++;
            if (A[end] == 1) end--;
        }
    }
