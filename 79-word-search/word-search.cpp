class Solution {
public:
    bool dfs(vector<vector<int>> & vis, int i, int j, vector<vector<char>>& board, string word, int index){
        if (index == word.length()) return true;
        vis[i][j] = 1;
        for (int a: {-1, 0, 1}){
            for (int b: {-1, 0, 1}){
                int r = i+a;
                int c = j+b;
                if (abs(a)+abs(b)==2) continue;
                if (r<0 || c<0 || r>=board.size() || c>=board[0].size()) continue;
                if (vis[r][c] == 0){
                    if (board[r][c] == word[index]){
                        vis[r][c] = 1;
                        if (dfs(vis, r, c, board, word, index+1)) return true;
                        vis[r][c] = 0;
                    }
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector <pair<int, int>> first;
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (word[0] == board[i][j]) first.push_back({i, j});
            }
        }
        for(auto a: first){
            vector<vector<int>> vis(n, vector<int>(m, 0));
            int i = a.first;
            int j = a.second;
            if (dfs(vis, i, j, board, word, 1)) return true;
        }
        return false;
    }
};