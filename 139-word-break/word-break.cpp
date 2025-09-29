class Solution {
public:
    bool helper(string& s, unordered_set<string> &st, int i, int& n, vector<int>& dp){
        if (i == n) return true;

        if (dp[i]!=-1) return dp[i];

        bool wordConsidered = false;
        string substr; 

        for (int j = i; j < n; j++){
            substr+=s[j];
            if (st.count(substr)){
                wordConsidered = helper(s, st, j+1, n, dp);
                if (wordConsidered) return dp[i] = true;
            }
        }

        
        return dp[i] = wordConsidered;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<int> dp(n+1, -1);
        return helper(s, st, 0, n, dp);
    }
};