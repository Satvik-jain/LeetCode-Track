class Solution {
public:
    bool helper(string& s, unordered_set<string> &st, string substr, int i, int& n, unordered_map<string, int> &dp){
        if (i == n){
            if (substr == "") return true;
            else return false;
        }

        string key = to_string(i) + "#" + substr;
        
        if (dp.count(key)) return dp[key];

        substr+=s[i];

        bool wordConsidered = false, wordNotConsidered = false;

        if (st.count(substr)){
            wordConsidered = helper(s, st, "", i+1, n, dp);
        }

        wordNotConsidered = helper(s, st, substr, i+1, n, dp);
        
        return dp[key] = (wordConsidered || wordNotConsidered);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.length();
        unordered_map<string, int> dp;
        return helper(s, st, "", 0, n, dp);
    }
};