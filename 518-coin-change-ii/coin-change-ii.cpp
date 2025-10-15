class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sum = amount;
        int n = coins.size();

        vector<vector<unsigned int>> dp(n, vector<unsigned int>(sum+1, 0));
        for (int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 1; j < sum+1; j++){
                unsigned int taken = 0, not_taken = 0;
                if (coins[i] <= j) taken = dp[i][j-coins[i]];
                if (i) not_taken = dp[i-1][j];
                dp[i][j] = (taken + not_taken);
            }
        }
        
        return dp[n-1][sum];
    }
};