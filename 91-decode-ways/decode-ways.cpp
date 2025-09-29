class Solution {
public:
    int helper(string &s, int i, int &ans, vector<int>& dp){
        if (i>=s.length()){
            return 1;
        }
        if (s[i]=='0') return 0;
        if (dp[i]!=-1){
            return dp[i];
        }
        int a = 0;
        if (s[i]=='1' || s[i]=='2'){
            if (i+1 < s.length()){
                int dig = s[i+1] - '0';
                if (s[i] == '1' || ((s[i] == '2') && dig>=0 && dig<=6)){
                    a = helper(s, i+2, ans, dp);
                }
            }
        }
        return dp[i] = a + helper(s, i+1, ans, dp);
    }

    int numDecodings(string s) {
        if (s[0] == '0') return false;
        vector<int> dp(s.length() + 1, -1);
        int ans = 0;
        return helper(s, 0, ans, dp);
    }
};