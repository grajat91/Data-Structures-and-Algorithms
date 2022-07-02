/*Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
*/
//O(N) space
    string minRemoveToMakeValid(string s) {
        stack<int> parantheses_stack;
        stack<int> bad_stack;
        
        for (int i=0;i<s.length();i++) {
            if (s[i] == '(') parantheses_stack.push(i);
            
             else if (s[i] == ')') {
                if (parantheses_stack.empty()) bad_stack.push(i);
                else parantheses_stack.pop();
            }
        }
        while (!parantheses_stack.empty()) {
            s.erase(parantheses_stack.top(),1);
            parantheses_stack.pop();
        }
        
        while (!bad_stack.empty()) {
            s.erase(bad_stack.top(),1);
            bad_stack.pop();
        }
        return s;
    }

//O(1) space

    int minAddToMakeValid(string s) {
        int left=0;
        int right=0;
        for (auto c : s) {
            if (c == '(') left++;
            else {
                if (left==0) right++;
                else left--;
            }
        }
        return left+right;
    }
