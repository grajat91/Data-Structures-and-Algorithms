/*Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 
Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701*/

int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int j=0;
        int result=0;
        for (int i=n-1;i>=0;i--) {
            result+=pow(26,j)*(columnTitle[i]-'A'+1);
            j++;
        }
        return result;
}
