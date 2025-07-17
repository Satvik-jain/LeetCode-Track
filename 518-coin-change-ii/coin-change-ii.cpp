class Solution {
  public:
  using ll = __int128;
    ll change(int sum, vector<int>& arr) {
        // code here.
        if (sum == 0) return 1;
        int n = arr.size();
        vector<vector<ll>> dp(n+1, vector<ll>(sum+1, 0));
        for (int i = 0; i < n + 1; i++){
            dp[i][0] = 1;
        }
        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < sum+1; j++){
                if (j >= arr[i-1]){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-arr[i-1]])%int(INT_MAX);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};