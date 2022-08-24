/*A mirror number is a number that looks the same when rotated 180 degrees (looked at upside down).For example, the numbers "69", "88", and "818" are all mirror numbers.
Write a function to determine if a number is mirror. The number is represented as a string.

Example
Example 1:

Input : "69"
Output : true
Example 2:

Input : "68"
Output : false*/

bool isStrobogrammatic(string &num) {

        unordered_set<char> individual_sgm;
        individual_sgm.insert('0');
        individual_sgm.insert('1');
        individual_sgm.insert('8');
        int left = 0;
        int right = num.size()-1;

        while(left <= right) {
            if ((num[left] == num[right]) && (individual_sgm.find(num[left]) != individual_sgm.end())) {
                left++;
                right--;
            }
            else {
                if ((num[left] == '6' && num[right] == '9') || (num[left] == '9' && num[right] == '6')) {
                    left++;
                    right--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
