class Solution {
public:
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if (i > j) return 0;
        int mine = INT_MAX;
        if (dp[i][j]!=-1) return dp[i][j];
        for (int ind = i; ind <= j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + helper(i, ind-1, cuts, dp) + helper(ind+1, j, cuts, dp);
            mine = min(mine, cost);
        }
        return dp[i][j] = (mine==INT_MAX)?0:mine;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return helper(1, c-2, cuts, dp);
    }
};