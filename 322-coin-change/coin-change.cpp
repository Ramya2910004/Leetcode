class Solution {
public:
int help(vector<int>& coins, int rem, vector<int>& dp) {
        if (rem == 0) return 0;
        if (rem < 0) return -1;
        if (dp[rem] != -2) return dp[rem];
        int mini = INT_MAX;
        for (int coin : coins) {
            int res = help(coins, rem - coin, dp);
            if (res >= 0 && res < mini)
                mini = 1 + res;
        }
        dp[rem] = (mini == INT_MAX) ? -1 : mini;
        return dp[rem];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        return help(coins, amount, dp);
    }
};