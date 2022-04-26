/*Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.


Example 1:

Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.*/ 

vector<int> findUnion(int A[], int B[], int N, int M)
    {
        int i=0,j=0;
        vector<int> res;
        while (i<N && j<M)
        {
            if (A[i] < B[j]) {
                if (res.size() && res.back ()!= A[i])
                    res.push_back(A[i]);
                else if (!res.size()) res.push_back(A[i]);
                i++;
            }
            else
            {
                if (res.size() && res.back ()!= B[j])
                    res.push_back(B[j]);
                else if (!res.size()) res.push_back(B[j]);
                j++;
            }
        }
        //i++;
        while (i<N) {
            if (res.size() && res.back ()!= A[i]) res.push_back(A[i]);
            i++;
        }
        while (j<M) {
            if (res.size() && res.back ()!= B[j]) res.push_back(B[j]);
            j++;
        }
        return res;
    }
