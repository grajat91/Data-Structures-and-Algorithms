/*A parentheses string is valid if and only if:
It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3*/

    int minAddToMakeValid(string s) {
        stack<char> parantheses_stack;
        int result=0;
        for (auto c : s) {
            if (c == '(') parantheses_stack.push(c);
            else {
                if (parantheses_stack.empty()) result++;
                else parantheses_stack.pop();
            }
        }
        
        
        result+=parantheses_stack.size();
        
        return result;
    }
