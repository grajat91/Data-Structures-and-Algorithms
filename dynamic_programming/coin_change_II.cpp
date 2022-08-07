/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1*/
//RECURSION
    int change_util(int amount, vector<int>& coins, int n) {
        if (amount == 0) return 1;
        if (n==0) return 0;
        if (coins[n-1] > amount) return change_util(amount, coins,n-1);
        return change_util(amount, coins,n-1) + change_util(amount-coins[n-1], coins,n);
    }

    int change(int amount, vector<int>& coins) {
        return change_util(amount,coins,coins.size());
    }

//TABULATION
    int change(int amount, vector<int>& coins) {
        int num_coins = coins.size();
        int dp[amount+1][num_coins+1];
        for (int i=0;i<=amount;i++) dp[i][0] = 0;
        for (int i=0;i<=num_coins;i++) dp[0][i] = 1;
        
        for (int i=1;i<=amount;i++) {
            for (int j=1;j<=num_coins;j++) {
                dp[i][j] = dp[i][j-1];
                if (coins[j-1] <= i) {
                    dp[i][j]+=dp[i-coins[j-1]][j];
                }
            }
        }
        return dp[amount][num_coins];
    }
