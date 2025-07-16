class Solution {
  public:
    // bool f(vector<int>& arr, int n, int W, vector<vector<int>> &dp){
    //     if (dp[n][W] != -1) return dp[n][W];
    //     if (W == 0) return 1;
    //     if (n == 0) return 0;
    //     if (W >= arr[n-1]) return dp[n][W] = (f(arr, n-1, W, dp) || f(arr, n-1, W-arr[n-1], dp));
    //     else return dp[n][W] = f(arr, n-1, W, dp);
    // }
    bool canPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum+=arr[i];
        }
        if (sum%2!=0) return false;
        int W = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for (int i = 0; i < n+1; i++){
            dp[i][0] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1; i < n+1; i++){
            for (int j = 1; j < W+1; j++){
                if (j >= arr[i-1]) dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);   
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][W];
    }
};