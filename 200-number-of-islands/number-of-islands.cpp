class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '1' && vis[i][j] == 0){
                    ans++;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        vis[r][c] = 1;
                        q.pop();
                        int ra[] = {-1, 0, 1, 0};
                        int ca[] = {0, -1, 0, 1};
                        for(int i = 0; i < 4; i++){
                            int nr = r+ra[i];
                            int nc = c+ca[i];
                            if (nc<0||nr<0||nc>=m||nr>=n) continue;
                            if (grid[nr][nc] == '1' && vis[nr][nc] == 0){
                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};