class Solution {
public:
    bool helper(const string &s1,const string &s2,const string &s3, int a, int b, int i, vector<vector<int>>& dp){
        if (i == s3.size() && a == s1.size() && b == s2.size()) return true;
        if (dp[a][b] != -1) return dp[a][b];
        if (s1[a] == s3[i] && helper(s1, s2, s3, a+1, b, i+1, dp)) return dp[a][b] = true;
        if (s2[b] == s3[i] && helper(s1, s2, s3, a, b+1, i+1, dp)) return dp[a][b] = true;
        return dp[a][b] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size()!=s1.size()+s2.size()) return false;
        if(s1+s2 == s3) return true;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return helper(s1, s2, s3, 0, 0, 0, dp);
    }
};