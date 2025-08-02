class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int travel = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            vis[r][c] = 1;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr<0 || nc<0 || nr>=n || nc >= m) continue;
                if (vis[nr][nc] == 1) continue;
                if (image[nr][nc] == travel){
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};