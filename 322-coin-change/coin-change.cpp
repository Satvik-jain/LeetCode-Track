class Solution {
public:
    int helper(vector<int>& coins, int amount, int n, int i, vector<vector<int>> &dp){
        if (amount == 0) return 0;
        if (amount < 0) return 1e9;

        if (dp[i][amount]!=-1) return dp[i][amount];

        int take = 1e9, not_take = take;

        if (coins[i] <= amount){
            take = 1 + helper(coins, amount-coins[i], n, i, dp);
        }

        if (i+1 < n) not_take = helper(coins, amount, n, i+1, dp);

        return dp[i][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = helper(coins, amount, n, 0, dp);
        return (ans == 1e9) ? -1 : ans;
    }
};