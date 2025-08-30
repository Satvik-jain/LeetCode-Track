class Solution {
public:
bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int PP(string &s, int i, vector<int>& dp){
        if (i == s.length()) return 0;
        int n = s.length();
        int mine = INT_MAX;
        if (dp[i]!=-1) return dp[i];
        for(int j = i; j < n; j++){
            if (isPalindrome(s, i, j)){
                int ways = 1 + PP(s, j+1, dp);
                mine = min(mine, ways);
            }
        }
        return dp[i] = mine;
    }
    int minCut(string &s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return PP(s, 0, dp)-1;
    }
};