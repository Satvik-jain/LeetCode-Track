class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        using P = tuple<int, int, int>;
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        vis[0][0] = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0,0,0});
        while(!q.empty()){
            int d = get<0>(q.top());
            int a = get<1>(q.top());
            int b = get<2>(q.top());
            q.pop();
            if (a == n-1 && b == m-1) return d;
            for (int i : {-1,0,1}){
                for (int j: {-1, 0, 1}){
                    if (i==0&&j==0)continue;
                    if (abs(i)+abs(j) == 2) continue;
                    int r = i+a; int c = j+b;
                    if(r<0||c<0||r>=n||c>=m) continue;
                    if (vis[r][c] > max(d, abs(grid[r][c] - grid[a][b]))){
                        q.push({max(d, abs(grid[r][c] - grid[a][b])), r, c});
                        vis[r][c] = max(d, abs(grid[r][c] - grid[a][b]));
                    }
                }
            }
        }
        return -1;
    }
};