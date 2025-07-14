class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if (j1<0||j1>=m||j2<0||j2>=m) return -1e8;
        if (i==n-1){
            return dp[i][j1][j2] = (j1==j2)? grid[i][j1] : grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int dj[] = {-1, 0, 1};
        int maxe = -1e8;
        for (int a : dj){
            for (int b : dj){
                maxe = (j1 == j2)? max(maxe, grid[i][j1] + f(grid, i+1, j1+a, j2+b, dp)) : max(maxe, grid[i][j2] + grid[i][j1] + f(grid, i+1, j1+a, j2+b, dp));
            }
        }
        return dp[i][j1][j2] = maxe;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, -1)));
        return f(grid, 0, 0, m-1, dp);
    }
};