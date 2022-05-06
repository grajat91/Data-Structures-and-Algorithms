/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> result;
        int n = temperatures.size();
        s.push(n-1);
        result.push_back(0);
        for (int i=n-2;i>=0;i--) {
            while (s.empty() == false && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if (s.empty()==false) {
                int count = s.top()-i;
                result.push_back(count);
            } else {
                result.push_back(0);
            }
            s.push(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
