/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"*/

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.length();
        int n = num2.length();
        vector<int>result(m+n,0);
        string answer;
        for (int i=num1.length()-1;i>=0;i--) {
            for (int j=num2.length()-1;j>=0;j--) {
                result[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                result[i+j] += result[i + j + 1]/10;
                result[i+j+1] = result[i + j + 1]%10;
            }
        }
        int i=0;
        while (result[i] == 0) i+=1;
        while (i<result.size()) {
            answer += to_string(result[i]);
            i++;
        }
        return answer;
    }
