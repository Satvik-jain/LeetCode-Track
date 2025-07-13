class Solution {
  public:
  int nCr(int n, int r, vector<vector<int>>& dp) {
  
    // No valid combinations if r is greater than n
    if(dp[n][r] != -1) return dp[n][r];
    if (r > n) 
        return dp[n][r] = 0;
  
    // Base case: only one way to choose 0 or all elements
    if (r == 0 || r == n) 
        return dp[n][r] = 1;
  
    // include or exclude current element
    return dp[n][r] = nCr(n - 1, r - 1, dp) + nCr(n - 1, r, dp);
}
    int uniquePaths(int m, int n) {
        // Code Here
        vector<vector<int>> dp(n+m+1, vector<int>(m+n+1, -1));
        return nCr(n-1+m-1, max(m-1,n-1), dp);
    }
};
