class Solution {
private:
    int bfs(vector<vector<int>>& vis, vector<vector<int>>& grid){
        queue <pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({{i,j},time});
                    vis[i][j]++;
                }
            }
        }
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            time = q.front().second;
            cout << a << " " << b << " " << time << endl;
            q.pop();
            for (auto i : {-1,0,1}){
                for (auto j: {-1,0,1}){
                    int newr = a + i;
                    int newc = b + j;
                    if (abs(i) + abs(j) == 2) continue;
                    if (newr >= 0 && newc >= 0 && newr < grid.size() && 
                        newc < grid[0].size()){
                        if (grid[newr][newc] == 1 && vis[newr][newc] == 0){
                            vis[newr][newc] = 1;
                            grid[newr][newc] = 2;
                            q.push({{newr, newc},time + 1});
                        }
                    }
                }
            }
        }
        return time;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int time = bfs(vis, grid);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};