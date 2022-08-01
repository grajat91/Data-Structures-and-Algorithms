/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23*/

    int minEatingSpeed(vector<int>& piles, int h) {
	    int max_elem = 0;
	    for (int num : piles) max_elem = max(max_elem,num);
	    int l = 1;
	    int r = max_elem;
        int result = r;
	    while (l <= r) {
		    int k = l + ((r-l)/2);
		    long int num_hours = 0;
		    for (int num : piles) {
			    if (num%k == 0) num_hours+=num/k;
			    else num_hours+=(num/k+1);
		    }
            //cout<<l<<" "<<r<<" "<<mid<<" "<<num_hours<<endl;
		    if (num_hours <= h) {
                result = min(k,result);
                r = k-1;
            }
            if (num_hours > h) l = k+1;
	    }
	    return result;
    }
