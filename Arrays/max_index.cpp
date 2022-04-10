/*Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
 Input:
N = 2
A[] = {1, 10}
Output:
1
Explanation:
A[0]<A[1] so (j-i) is 1-0 = 1.*/

int maxIndexDiff(int A[], int N) 
{ 
        int max = INT_MIN;
        for (int i=0; i<N; i++) {
            int j=N-1;
            while (i<j) {
                if (A[i]>A[j]) {
                    j--;
                }
                else {
                    A[i]=j-i;
                }
                A[i]=-1;
            }
        }
        
        for (int i=0;i<N;i++) {
            if (A[i] > max) {
                max = A[i];
            }
        }
        return max;
 }
