class Solution {
public:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
        if (j>triangle[i].size()-1) return 1e9;
        if (i<0||j<0) return 1e9;
        if (dp[i][j]!=-1) return dp[i][j];
        if (i==0) return dp[i][j] = triangle[i][j];
        int l = helper(triangle, dp, i-1, j-1);
        int u = helper(triangle, dp, i-1, j);
        return dp[i][j] = min(triangle[i][j]+l, triangle[i][j]+u);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        int ans=INT_MAX;
        for (int i = 0; i < m; i++){
            vector<vector<int>> dp(n, vector<int>(m, -1));
            ans = min(ans, helper(triangle, dp, n-1, i));
        }
        return ans;
    }
};