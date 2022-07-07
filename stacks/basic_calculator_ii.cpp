/*Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5*/

    int calculate(string s) {
        int curr = 0;
        int res = 0;
        char sign = '+';
        stack<int> intermediate;
        for (unsigned int i=0;i<s.size();i++) {
            if (isdigit(s[i])) curr = curr*10 + (s[i]-'0');
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
                if (sign == '-') intermediate.push(-curr);
                else if (sign == '+') intermediate.push(curr);
                else {
                    int num;
                    if (sign == '*') {
                        num = intermediate.top()*curr;
                    } else {
                        num = intermediate.top()/curr;
                    }
                    intermediate.pop();
                    intermediate.push(num);
                }
                sign = s[i];
                curr = 0;
            }
        }
        
        while (!intermediate.empty()) {
            res+= intermediate.top();
            intermediate.pop();
        }
        
        return res;
    }
