class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }
        for (int depth = n-2; depth >= 0; depth--){
            for (int column = 0; column < n; column++){
                int i = depth, j = column;
                int down = dp[i + 1][j];
                int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;
                dp[depth][column] = matrix[i][j] + min(min(
                                        left,
                                        down), 
                                    right
                                    );
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};