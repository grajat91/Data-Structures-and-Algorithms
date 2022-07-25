/*Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.*/

    int mySqrt(int x) {
        int l,h;
        double mid;
        l=0;
        h=x;
        /*if (x==0 || x==1) {
            return x;
        }*/
        while (l<=h) {
            mid = h + (l-h)/2;
            if (mid*mid == x) {
                return mid;
            }
            if (mid*mid > x) {
                h=mid-1;
            }
            if (mid*mid < x) {
                l = mid + 1;
            }
        }
        return h;
    }
