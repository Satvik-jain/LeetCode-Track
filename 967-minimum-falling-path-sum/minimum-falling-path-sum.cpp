class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> dp(n , -1);
        for (int j = 0; j < n; j++) {
            dp[j] = matrix[n-1][j];
        }
        for (int depth = n-2; depth >= 0; depth--){
            vector<int> temp(n, -1);
            for (int column = 0; column < n; column++){
                int i = depth, j = column;
                int down = dp[j];
                int left = (j > 0) ? dp[j - 1] : INT_MAX;
                int right = (j < n - 1) ? dp[j + 1] : INT_MAX;
                temp[j] = matrix[i][j] + min(min(
                                        left,
                                        down), 
                                    right
                                    );
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};