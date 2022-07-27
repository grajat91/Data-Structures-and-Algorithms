/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]*/

    void generateParenthesis_util(vector<string>& result, string str, int m, int n) {
        if (m==0 && n==0) {
            result.push_back(str);
            return;
        }
        if (n>0) generateParenthesis_util(result,str+"(",m+1,n-1);
        if (m>0) generateParenthesis_util(result,str+")",m-1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis_util(result,"",0,n);
        return result;
    }
