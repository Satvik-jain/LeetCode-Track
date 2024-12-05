class Solution {
private:
    void bfs(vector<vector<int>>& vis, int color, int sr, int sc, vector<vector<int>>& image){
        queue <pair<int, int>> q;
        q.push({sr,sc});
        int oldcolor = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            for (auto i : {-1,0,1}){
                for (auto j: {-1,0,1}){
                    int newr = sr + i;
                    int newc = sc + j;
                    if (abs(i) + abs(j) == 2) continue;
                    if (newr >= 0 && newc >= 0 && newr < image.size() && 
                        newc < image[0].size()){
                        if (image[newr][newc] == oldcolor && vis[newr][newc] == 0){
                            vis[newr][newc] = 1;
                            image[newr][newc] = color;
                            q.push({newr, newc});
                        }
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        bfs(vis, color, sr, sc, image);
        return image;
    }
};