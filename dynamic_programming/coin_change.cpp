/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1*/

    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        //for (int i=1;i<=amount;i++) dp[i] = INT_MAX;
         for (int i=1;i<=amount;i++) {
             dp[i] = INT_MAX;
             for (int j=0;j<coins.size();j++) {
                 if (coins[j] <= i) {
                     int subres = dp[i-coins[j]];
                     if (subres != INT_MAX) {
                         dp[i] = min(dp[i],1+subres);
                     }
                 }
             }
         }
        return (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
