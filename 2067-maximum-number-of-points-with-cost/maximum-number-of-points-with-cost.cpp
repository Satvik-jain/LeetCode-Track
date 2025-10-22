class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = points[i][j];

        for (int i = 0; i < n-1; i++){
            vector<long long> left(m, 0), right(m, 0), maximum(m, 0);
            left[0] = dp[i][0];
            right[m-1] = dp[i][m-1];
            for (int j = 1; j < m; j++){
                left[j] = max(dp[i][j], (long long)left[j-1] - 1);
            }
            for (int j = m-2; j >= 0; j--){
                right[j] = max(dp[i][j], (long long)right[j+1]-1);
            } 
            for (int j = 0; j < m; j++){
                maximum[j] = max(left[j], right[j]);
            }
            for (int j = 0; j < m; j++){
                dp[i+1][j]+=maximum[j];
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};