class Solution {
public:
    void solve(vector<vector<char>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        queue <pair<int,int>> q;
        vector<vector<int>> vis(n , vector<int>(m, 0));
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < m; j++){
                
                if ((i == 0 || i == n-1) || (j == 0 || j == m-1)){
                    
                    if (mat[i][j]=='O'){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int i:{-1,0,1}){
                for (int j:{-1,0,1}){
                    if(abs(i)+abs(j) == 2) continue;
                    int r = a+i;
                    int c = b+j;
                    if (r>=0 && c>=0 && r < n && c < m){
                        if (mat[r][c] == 'O' && !vis[r][c]){
                            vis[r][c] = 1;
                            q.push({r,c});
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < m; j++){
                cout << vis[i][j];
                if(mat[i][j]=='O' && vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
            cout << endl;
        }
    }
};