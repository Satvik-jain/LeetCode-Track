class Solution {
private:
    // int cs(int n, vector <int> &dp){
        
    //     if (dp[n]!=-1) return dp[n];
    //     return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    // }

public:
    int climbStairs(int n) {
        if (n==0) return 1;
        int prev = 1;
        int prev2 = 1;
        for (int i = 2; i < n+1; i++){
            int curr = prev+ prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};