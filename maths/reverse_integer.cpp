/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21*/

    int reverse(int x) {
        if (x==0 || x == INT_MIN) return 0;
        int sign=1;
        if (x < 0) sign = -1;
        long reversed_x=0;
        x = sign*x;
        while (x != 0) {
            int last_dig = x%10;
            x = x/10;
            reversed_x = (reversed_x*10) + last_dig;
            if (reversed_x > INT_MAX || reversed_x < INT_MIN) return 0;
        }
        return sign*reversed_x;
        
    }
