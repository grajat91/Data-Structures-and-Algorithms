/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]*/

    void letterCombinations_util(string digits, vector<string>& digits_to_strings, vector<string>& letter_combinations, int i, string leaf) {
        if (i == digits.length()) {
            letter_combinations.push_back(leaf);
            return;
        }
        int d = digits[i] - '0';
        for (char c : digits_to_strings[d]) {
            letterCombinations_util(digits, digits_to_strings, letter_combinations, i+1, leaf+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.length()) return {};
        vector<string> letter_combinations;
        vector<string> digits_to_strings =  { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string leaf;
        letterCombinations_util(digits, digits_to_strings, letter_combinations, 0, leaf);
        return letter_combinations;
    }
