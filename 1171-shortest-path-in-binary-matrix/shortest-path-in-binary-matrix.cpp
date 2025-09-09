class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        using P = tuple<int, int, int>;
        vector<vector<int>> vis(n, vector<int>(n, -1));
        queue<P> q;
        q.push({1,0,0});
        while(!q.empty()){
            int d = get<0>(q.front());
            int a = get<1>(q.front());
            int b = get<2>(q.front());
            q.pop();
            if (a == n-1 && b == n-1) return d;
            for (int i : {-1,0,1}){
                for (int j: {-1, 0, 1}){
                    if (i==0&&j==0)continue;
                    int r = i+a; int c = j+b;
                    if(r<0||c<0||r>=n||c>=n) continue;
                    if (grid[r][c] == 0 && vis[r][c] == -1){
                        q.push({d+1, r, c});
                        vis[r][c] = 1;
                    }
                }
            }
        }
        return -1;
    }
};