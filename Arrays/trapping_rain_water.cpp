/*Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.*/

    long long trappingWater(int arr[], int n){
        int maxL = arr[0];
        int maxR = arr[n-1];
        int maxLarr[n];
        int maxRarr[n];
        long long sum=0;
        maxLarr[0] = maxRarr[0] = arr[0];
        maxRarr[n-1] = maxLarr[n-1] = arr[n-1];
        
        for (int i=1;i<n-1;i++) {
            if (arr[i-1]>maxL) {
                maxL = arr[i-1];
            }
            maxLarr[i] = maxL;
        }
        
        for (int i=n-2;i>0;i--) {
            if (arr[i+1]>maxR) {
                maxR = arr[i+1];
            }
            maxRarr[i] = maxR;
        }
        
        for (int i=0; i<n; i++) {
            long long inter = min(maxLarr[i],maxRarr[i]) - arr[i];
            if (inter < 0) {
                inter = 0;
            }
            sum+=inter;
        }
        return sum;
    }
