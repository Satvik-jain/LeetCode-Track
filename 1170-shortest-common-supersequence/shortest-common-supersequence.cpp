class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string s1 = str1, s2 = str2;
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){ 
                if (s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int i = n;
        int j = m;
        string s;
        while(i>0 && j>0){
            if (s1[i-1] == s2[j-1]){
                s.push_back(s1[i-1]);
                i--; j--;
            }
            else{
                if (dp[i-1][j] > dp[i][j-1]){
                    s.push_back(s1[i-1]);
                    i--;
                }
                else if (dp[i-1][j] <= dp[i][j-1]){
                    s.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i > 0){
            s.push_back(s1[i-1]);
            i--;
        }
        while(j > 0){
            s.push_back(s2[j-1]);
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};