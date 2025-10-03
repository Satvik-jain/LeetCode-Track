class Solution {
public:
    int helper(string &a, string &b, int n, int m, vector<vector<int>>& t){
        if (m==0 || n==0) return 0;
        if (t[n][m] != -1) return t[n][m];
        if (a[n-1] == b[m-1]){
            return t[n][m] = 1 + helper(a, b, n-1, m-1, t);
        }
        return t[n][m] = max(helper(a, b, n, m-1, t), helper(a, b, n-1, m, t));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if (m==0 || n==0) return 0;
        vector<vector<int>> t(n+1, vector<int>(m+1, -1));
        return helper(text1, text2, n, m, t);
    }
};