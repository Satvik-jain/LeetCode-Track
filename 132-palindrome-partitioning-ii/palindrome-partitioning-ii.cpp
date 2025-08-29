class Solution {
public:
bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int PP(string &s, int i, int j, vector<vector<int>>& dp, int ans){
        // cout << ans << endl;
        if (i >= j) return 0;
        if (isPalindrome(s, i, j)) return 0; // whole substring already palindrome
        if (dp[i][j] != -1) return dp[i][j];
        int cut = 0;
        for (int k = i; k < j; k++){
            if (isPalindrome(s, i, k)){
                cut = 1+PP(s,k+1,j, dp, ans);
                ans = min(ans, cut);
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string &s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int ans = INT_MAX;
        return PP(s, 0, s.length()-1, dp, ans);
    }
};