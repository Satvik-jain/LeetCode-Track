class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> v(10, 0);
        for (int i = 0; i < 9; i++){
            fill(v.begin(), v.end(), 0);
            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                if (v[board[j][i]-'0'] == 1) return false;
                v[board[j][i]-'0'] = 1;
            }
        }
        for (int i = 0; i < 9; i++){
            fill(v.begin(), v.end(), 0);
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (v[board[i][j]-'0']) return false;
                v[board[i][j]-'0'] = 1;
            }
        }
        for (int k = 0; k < 9; k++){
            fill(v.begin(), v.end(), 0);
            int row = (k/3) * 3;
            int col = (k%3) * 3;  
            for (int i = row; i < row+3; i++){
                for (int j = col; j < col+3; j++){
                    if (board[i][j] == '.') continue;
                    if (v[board[i][j]-'0']) return false;
                    v[board[i][j]-'0'] = 1;
                }
            }
        }
        
        return true;
    }
};