/*The intersection of two arrays contains the elements common to both the arrays. The intersection should not count duplicate elements.
Given two sorted arrays arr1[] and arr2[] of sizes N and M respectively. Find their intersection

 

Example 1:

Input: 
N = 4, arr1[] = {1, 2, 3, 4}  
M = 5, arr2 [] = {2, 4, 6, 7, 8}
Output: 2 4
Explanation: 2 and 4 are only common 
elements in both the arrays.*/

vector<int> printIntersection(int A[], int B[], int N, int M) 
    { 
        int i=0,j=0;
        vector<int> res;
        while (i<N && j<M)
        {
            if (A[i] < B[j]) i++;
            else
            {
                if (A[i] == B[j]) {
                    if (res.size()) {
                        if (res.back() != A[i]) res.push_back(A[i]);
                    } else res.push_back(A[i]);
                }
                j++;
            }
        }
        return res;
    }
