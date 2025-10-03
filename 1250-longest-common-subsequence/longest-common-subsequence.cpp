class Solution {
public:
    int LCS(string &s1, string &s2, vector<vector<int>>& dp, int i1, int i2){
        if (i1==0 || i2==0) return 0;
        if (dp[i1][i2]!=-1) return dp[i1][i2];

        if (s1[i1-1] == s2[i2-1]){
            return dp[i1][i2] = 1 + LCS(s1, s2, dp, i1-1, i2-1);
        }

        return dp[i1][i2] = max(LCS(s1, s2, dp, i1, i2-1), LCS(s1, s2, dp, i1-1, i2));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m==0 || n==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return LCS(s1, s2, dp, n, m);
    }
};