class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<vector<int>> &dp, int n, int index){
        if (index >= n) return 1e9;
        if (amount < 0) return 1e9;
        if (amount == 0) return 0;
        if (dp[index][amount]!=-1) return dp[index][amount];

        int taken = 1e9, not_taken = 1e9;

        if (coins[index]<=amount) taken = 1+helper(coins, amount-coins[index], dp, n, index);
        not_taken = helper(coins, amount, dp, n, index+1);

        return dp[index][amount] = min(taken, not_taken);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = helper(coins, amount, dp, n, 0);
        return (ans==1e9)?-1:ans;
    }
};