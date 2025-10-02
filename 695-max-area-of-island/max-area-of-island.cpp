class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        int maxe = 0, ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (vis[i][j] == 0 && grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                    ans = 0;
                    while(!q.empty()){
                        ans++;
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++){
                            int r = x+dr[k], c = y+dc[k];
                            if(r<0 || c<0 || r>=n || c>=m) continue;
                            if (vis[r][c] == 0 && grid[r][c] == 1){
                                q.push({r,c});
                                vis[r][c] = 1;
                            }
                        }
                    }
                }
                maxe = max(maxe, ans);
            }
        }
        return maxe;
    }
};