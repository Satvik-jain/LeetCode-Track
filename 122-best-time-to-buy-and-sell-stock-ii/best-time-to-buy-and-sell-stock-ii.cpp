
class Solution {
  public:
    int f(vector<int>& prices, int i, int buy, vector<vector<int>> & dp){
        int n = prices.size();
        if (i == n) return 0;
        if (dp[i][buy]!=-1) return dp[i][buy];
        if (buy){
            return dp[i][buy] = max(-prices[i] + f(prices, i+1, 0, dp), 0 + f(prices, i+1, 1, dp)); 
        }
        else{
            return dp[i][buy] = max(prices[i] + f(prices, i+1, 1, dp), 0 + f(prices, i+1, 0, dp)); 
        }
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, 1, dp);
    }
};
