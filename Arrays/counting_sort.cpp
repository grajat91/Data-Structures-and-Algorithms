/*Given a string arr consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort.

Example 1:
Input:
N = 5
S = "edsab"
Output:
abdes
Explanation: 
In lexicographical order, string will be 
abdes.*/

string countSort(string arr){
        string str = "";
        int count[26] = {0};
        
        for (int i=0;i<arr.length();i++)
        {
            count[arr[i]-'a']++;
        }
        for (int i=0;i<26;i++) {
            for (int j=0;j<count[i];j++) {
                char achar = 'a' + i;
                str = str+achar;
            }
        }
        return str;
    }
