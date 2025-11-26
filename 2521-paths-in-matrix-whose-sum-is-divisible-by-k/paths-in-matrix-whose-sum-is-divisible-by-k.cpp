class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n][k];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int rem = 0; rem < k; ++rem) {
                    if (i > 0) {
                        dp[i][j][(rem + grid[i][j]) % k] = (dp[i][j][(rem + grid[i][j]) % k] + dp[i - 1][j][rem]) % 1000000007;
                    }
                    if (j > 0) {
                        dp[i][j][(rem + grid[i][j]) % k] = (dp[i][j][(rem + grid[i][j]) % k] + dp[i][j - 1][rem]) % 1000000007;
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1][0];
    }
};