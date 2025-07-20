class Solution {
public:
    int f(vector<int> &a, int i, int buy, int k, vector<vector<vector<int>>>& dp){
        int n = a.size();
        if (i==n || k == 0) return 0;
        if (dp[i][buy][k] != -1) return dp[i][buy][k];
        if (buy) return dp[i][buy][k] = max(-1*a[i] + f(a, i+1, 0, k, dp), f(a, i+1, 1, k, dp));
        else return dp[i][buy][k] = max(a[i] + f(a, i+1, 1, k-1, dp), f(a, i+1, 0, k, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(prices, 0, 1, 2, dp);
    }
};