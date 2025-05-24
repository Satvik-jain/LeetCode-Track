class Solution {
public:
    void bfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            grid[r][c] = '0';
            q.pop();
            for(int i: {-1, 0, 1}){
                for(int j : {-1, 0, 1}){
                    int nr = r + i;
                    int nc = c + j;
                    if (nr<0 || nr > n-1 || nc<0 || nc > m-1) continue;
                    if(abs(i)+abs(j) == 2){
                        continue;
                    }
                    else{
                        if(grid[nr][nc] == '1'){
                            grid[nr][nc] = '0';
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]=='0') continue;
                else{
                    bfs(i, j, n, m, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};