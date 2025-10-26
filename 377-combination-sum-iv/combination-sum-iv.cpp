class Solution {
public:
    int helper(vector<int>& coins, int amount, vector<vector<int>> &dp, int n, int index){
        if (amount == 0) return 1;
        if (dp[index][amount]!=-1) return dp[index][amount];

        int taken = 0;

        for (int i = 0; i < n; i++){
            if (coins[i]<=amount) taken += helper(coins, amount-coins[i], dp, n, index);
        }
        return dp[index][amount] = taken;
    }

    int combinationSum4(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return helper(coins, amount, dp, n, 0);
    }
};