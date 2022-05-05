/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9*/

int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        int result;
        for (auto st : tokens) {
            if ((st != "/") && (st != "*") && (st != "-") && (st != "+")) {
                s.push(stoi(st));
            } else {
                int operand1 = s.top();
                s.pop();
                int operand2 = s.top();
                s.pop();
                if (st == "/") {result = operand2/operand1;} 
                if (st == "-") {result = operand2-operand1;}
                if (st == "+") {result = operand2+operand1;}
                if (st == "*") {result = operand2*operand1;}
                s.push(result);
            }
        }
        return s.top();
}
