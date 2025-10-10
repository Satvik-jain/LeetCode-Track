class Solution {
public:
    void helper(int n, vector<string>& ans, string s, int open, int close){
        if (open == n && close == n){
            ans.push_back(s); return;
        }
        string s_open = s+"(";
        string s_close = s+")";
        if (open > close) helper(n, ans, s_close, open, close+1);
        if (open < n) helper(n, ans, s_open, open+1, close);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans, "(", 1, 0);
        return ans;
    }
};