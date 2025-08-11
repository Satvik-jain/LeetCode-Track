class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size(); int m = grid[0].size();
        vis[i][j] = 1;
        
        int r[] = {-1,0,1,0};
        int c[] = {0,1,0,-1};
        int ans = 1;
        for (int k = 0; k < 4; k++){
            int nr = i+r[k], nc = j+c[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (vis[nr][nc] == -1 && grid[nr][nc] == 1){
                ans = ans+dfs(nr, nc, grid, vis);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        
        int maxe = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (vis[i][j] == -1 && grid[i][j] == 1){
                    maxe = max(maxe, dfs(i, j, grid, vis));
                    cout << "(" << i << "," << j << "): " << maxe << endl;
                }
            }
        }

        return maxe;
    }
};