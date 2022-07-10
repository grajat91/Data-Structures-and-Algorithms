/*Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
The test cases are generated so that the length of the output will never exceed 105.

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"*/

    int into_number(string x) {
        int rev = 0;
        for (char c : x) {
            rev = 10*rev + (c-'0');
        }
        return rev;
    }
    string decodeString(string s) {
        string curr_string;
        string prev_string;
        string curr_num;
        string num;
        int mult=0;
        stack<string> string_store;
        for (char c : s) {
            if (isdigit(c)) {
                curr_num += c;
            }
            else if(c == '[') {
                string_store.push(curr_string);
                string_store.push(curr_num);
                curr_string = "";
                curr_num = "";
            } else if(c == ']') {
                num = string_store.top();
                mult = into_number(num);
                string_store.pop();
                prev_string = string_store.top();
                string_store.pop();
                string n = prev_string;
                string p;
                for (int i=0;i<mult;i++) {
                    p += curr_string;
                }
                curr_string = n + p;
            } else {
                curr_string += c;
            }
        }
        return curr_string;
    }
