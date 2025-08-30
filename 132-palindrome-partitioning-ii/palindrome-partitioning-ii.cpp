class Solution {
public:
bool isPalindrome(string &s, int i, int j, vector<vector<int>> & pal) {
        while (i < j) {
            if (s[i] != s[j]) return pal[i][j] = false;
            i++; j--;
        }
        return pal[i][j] = true;
    }
    int minCut(string &s) {

        int n = s.length();
        vector<int> dp(n+1, 0);
        vector<vector<int>> pal(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--){
            int mine = INT_MAX;
            for(int j = i; j < n; j++){
                if (pal[i][j]==1 || isPalindrome(s, i, j, pal)){
                    int ways = 1 + dp[j+1];
                    mine = min(mine, ways);
                }
            }
            dp[i] = mine;
        }

        return dp[0]-1;
    }
};