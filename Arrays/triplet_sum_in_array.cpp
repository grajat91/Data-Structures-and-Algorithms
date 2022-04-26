/*Given an array of N elements and a number K. The task is to arrange array elements according to the absolute difference with K, i. e., element having minimum difference comes first and so on.
Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.
 

Example 1:

Input: N = 5, K = 7
arr[] = {10, 5, 3, 9, 2}
Output: 5 9 10 3 2
Explanation: Sorting the numbers accoding to 
the absolute difference with 7, we have 
array elements as 5, 9, 10, 3, 2.*/

bool find3Numbers(int A[], int n, int X)
    {
        int j,k;
        int sum=0;
        sort(A,A+n);
        for (int i=0;i<n-1;i++) {
            j = i+1;
            k = n-1;
            while (j<k) {
                sum = A[i]+A[j]+A[k];
                if (sum == X) {
                    return true;
                } else if (sum > X) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return false;
    }
