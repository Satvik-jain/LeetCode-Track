class Solution {
public:
    int helper(int W, vector<int> &coins, int index, vector<vector<int>>& dp){
        if (W == 0) return 1;
        if (W < 0) return 0;
        if (index >= coins.size()) return 0;
        if (dp[W][index] != -1) return dp[W][index];
        int tot = 0;
        if (coins[index] <= W) tot+=helper(W-coins[index], coins, index, dp);
        tot+=helper(W, coins, index+1, dp);
        return dp[W][index] = tot;
    }
    int change(int amount, vector<int>& coins) {
        int W = amount;
        int n = coins.size();
        vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
        return helper(W, coins, 0, dp);
    }
};