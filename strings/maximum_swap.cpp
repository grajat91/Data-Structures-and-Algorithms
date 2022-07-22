/*You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.*/

    int maximumSwap(int num) {
        string numstr = to_string(num);
        int leftindex=-1;
        int rightindex;
        int max_elem = INT_MIN;
        int maxindex;
        for (int i=numstr.size()-1;i>=0;i--) {
            if (numstr[i] > max_elem) {
                max_elem = numstr[i];
                maxindex = i;
                continue;
            }
            if (numstr[i] < max_elem) {
                leftindex=i;
                rightindex=maxindex;
            }
        }
        if (leftindex == -1) return num;
        else swap(numstr[leftindex],numstr[rightindex]);
        return stoi(numstr);
    }
