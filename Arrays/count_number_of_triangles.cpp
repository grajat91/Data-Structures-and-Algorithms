/*Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 

Example 1:
Input: 
n = 3
arr[] = {3, 5, 4}
Output: 
1
Explanation: 
A triangle is possible 
with all the elements 5, 3 and 4.*/

int findNumberOfTriangles(int arr[], int n)
    {
        int j,k,l;
        //int sum=0;
        int count=0;
        sort(arr,arr+n);
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                k=j+1;
                while ((k<n) && (arr[i] + arr[j] > arr[k])) {
                    count++;
                    k++;
                }
            }
        }
        
        return count;
    }
