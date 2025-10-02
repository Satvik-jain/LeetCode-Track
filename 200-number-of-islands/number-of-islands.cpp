class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                if (vis[r][c] == 0 && grid[r][c] == '1'){
                    ans++;
                    q.push({r,c});
                    vis[r][c] = 1;
                    while(!q.empty()){
                        int i = q.front().first;
                        int j = q.front().second;
                        q.pop();
                        int x[] = {-1,0,1,0};
                        int y[] = {0,1,0,-1};
                        for (int k = 0; k < 4; k++){
                            int a = i+x[k], b = j+y[k];
                            if (a < 0 || b < 0 || a>=n || b>=m) continue;
                            if (vis[a][b] == 0 && grid[a][b] == '1'){
                                q.push({a, b});
                                vis[a][b] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};