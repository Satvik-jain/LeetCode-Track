class Solution {
public:
// int helper(int n, vector<int> &dp){
//     if (n==1) return 1;
//     if (n==2) return 2;
//     if (dp[n] != -1) return dp[n];
//     return dp[n] = helper(n-1, dp) + helper(n-2, dp); 
// }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2;
        int c;
        for (int i = 3; i < n+1; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};