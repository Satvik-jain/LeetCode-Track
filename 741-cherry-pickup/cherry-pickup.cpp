class Solution {
public:
    int f(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp){
        int n = grid.size();
        int m = n;
        if (i1>=n||i2>=n||j1>=m||j2>=m) return -1e9;
        if  (i1 == n-1 && j1 == n-1 && i2 == n-1 && j2 == n-1) return dp[i1][j1][i2][j2] = grid[n-1][n-1];
        if (dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        
        int id[] = {1, 0, 1, 0};
        int jd[] = {0, 1, 0, 1};
        int ir[] = {1, 0, 0, 1};
        int jr[] = {0, 1, 1, 0};
        int maxe = -1e8;
        for (int i = 0; i < 4; i++){
            int a1 = id[i]+i1, b1 = jd[i]+j1, a2 = ir[i]+i2, b2 = jr[i]+j2;
            if (a1 >= n || b1 >= m || a2 >= n || b2 >= m) continue;
            if (grid[a1][b1] == -1 && grid[a2][b2] == -1) continue;
            int p1 = -1e8;
            int p2 = -1e8;
            if (grid[i1][j1]!=-1) p1 = grid[i1][j1];
            if (grid[i2][j2]!=-1) p2 = grid[i2][j2];
            maxe = (i1 == i2 && j1 == j2)?max(maxe, p1+f(a1,b1,a2,b2,grid,dp)):max(maxe, p1+p2+f(a1,b1,a2,b2,grid,dp));
        }
        return dp[i1][j1][i2][j2] = maxe;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n;
        if (grid[0][0] == -1 || grid[n-1][n-1] == -1) return 0;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
        return  max(0, f(0, 0, 0, 0, grid, dp));
    }
};