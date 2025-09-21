class Solution {
public:
    vector<pair<int, int>> v;
    int dp[601][101][101];
    int helper(int m, int n, int ind) {
        if(ind == v.size() || (m == 0 && n == 0)) return 0;
        if(dp[ind][m][n] != -1) return dp[ind][m][n];
        if(v[ind].first > m || v[ind].second > n) return dp[ind][m][n] = helper(m, n, ind + 1);

        int pick = 1 + helper(m - v[ind].first, n - v[ind].second, ind + 1);
        int not_pick = helper(m, n, ind + 1);
        return dp[ind][m][n] = max(pick, not_pick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        v.clear();
        memset(dp, -1, sizeof(dp));
        for(string s: strs) {
            int zero = 0, one = 0;
            for(char c: s) {
                if(c == '1') one++;
                else zero++;
            }
            v.push_back({zero, one});
        }
        return helper(m, n, 0);
    }
};