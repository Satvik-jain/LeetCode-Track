class Solution {
public:
    int helper(vector<int>& cost, vector<int>& dp, int &n, int i){
        if (i == n || i == n+1) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(helper(cost, dp, n, i+1), helper(cost, dp, n, i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(helper(cost, dp, n, 0), helper(cost, dp, n, 1));
    }
};