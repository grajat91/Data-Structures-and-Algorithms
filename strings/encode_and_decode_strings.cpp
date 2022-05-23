/*Description
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
Please implement encode and decode

Example1
Input: ["lint","code","love","you"]
Output: ["lint","code","love","you"]
Explanation:
One possible encode method is: "lint:;code:;love:;you"

Example2
Input: ["we", "say", ":", "yes"]
Output: ["we", "say", ":", "yes"]
Explanation:
One possible encode method is: "we:;say:;:::;yes"*/

string encode(vector<string> &strs) {
    string result;
    for (auto it : strs) {
        int len = it.length();
        result+=to_string(len);
        result+="#";
        result+=it;
    }
    return result;
}


vector<string> decode(string &str) {
    vector<string> result;
    int i=0;
    while (str != "") {
        int pos = str.find('#');
        int word_length = stoi(str.substr(0, pos));
        result.push_back(str.substr(pos+1,word_length));
        str = str.substr(pos+word_length+1);
    }
    return result;
}
