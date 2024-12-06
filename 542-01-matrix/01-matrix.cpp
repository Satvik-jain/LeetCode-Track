class Solution {
private:
    void helper(vector<vector<int>>& mat){
        vector<vector<int>> vis(mat.size(), vector<int> (mat[0].size(), 0));
        int m =mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>,int>> q;
        int step = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j},step});
                }
            }
        }
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            step = q.front().second;
            q.pop();
            for(int i: {-1,0,1}){
                for (int j: {-1,0,1}){
                    if (abs(i) + abs(j) == 2) continue;
                    int r = a+i;
                    int c = b+j;
                    if(r>=0&& c>=0&& r<mat.size()&& c<mat[0].size()){
                        if(!vis[r][c] && mat[r][c] == 1){
                            mat[r][c] = step+1;
                            vis[r][c] = 1;
                            q.push({{r,c},step+1});
                        }
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m =mat.size();
        int n = mat[0].size();
        helper(mat);
        return mat;
    }
};