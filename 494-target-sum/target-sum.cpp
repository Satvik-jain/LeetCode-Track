class Solution {
  public:
    int findTargetSumWays(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int W = (sum+d)/2;
        if (d > sum || -1*sum > d) return 0;
        if ((sum+d)%2 != 0) return 0;
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        for (int i = 0; i < n+1; i++){
            dp[i][0] = 1;
        }
        for (int i = 1; i < n+1; i++){
            for (int j = 0; j < W+1; j++){
                if (j >= arr[i-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][W];
    }
};