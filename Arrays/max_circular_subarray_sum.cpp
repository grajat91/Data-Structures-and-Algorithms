/*Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.
Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.*/

int normalsubarraysum(int arr[], int num) {
        int max_ending = arr[0];
        int result = arr[0];
        for (int i=1; i<num; i++) {
            max_ending = max(max_ending+arr[i],arr[i]);
            result = max(result,max_ending);
        }
        return result;
    }
    
    int circularSubarraySum(int arr[], int num){
        
        int max_normal = normalsubarraysum(arr,num);
        if (max_normal < 0) {
            return max_normal;
        }
        
        int sum = 0;
        for (int i=0; i<num; i++) {
            sum+=arr[i];
            arr[i]=-arr[i];
        }
        int minsum = normalsubarraysum(arr,num);
        int finalsum = sum + minsum;
        int finalresult = max(finalsum,max_normal);
        return finalresult;
    }
