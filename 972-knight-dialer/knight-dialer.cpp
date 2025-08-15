class Solution {
public:
    int MOD = 1000000000+7;
    int helper(int n, vector<vector<int>>& map, vector<vector<int>> &dp, int pos){
        if (n==0){
            return 1;
        }
        if (dp[n][pos]!=-1) return dp[n][pos];
        int ways = 0;
        for(int i: map[pos]){
            ways = (ways+helper(n-1, map, dp, i))%MOD;
        }
        return dp[n][pos] = ways;
    }
    int knightDialer(int n) {
        vector<vector<int>> map = {
            {4, 6},
            {8, 6},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        
        vector<vector<int>> dp(n+1, vector<int>(10, -1));

        int ans = 0;

        for (int i = 0; i < 10; i++){
            ans = (ans + helper(n-1, map, dp, i))%MOD;
        }

        return ans;
    }
};