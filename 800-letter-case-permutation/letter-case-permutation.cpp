class Solution {
public:
    void helper(string s, string op, vector<string> &v){
        if (s.empty()){
            v.push_back(op);
            return;
        }

        if (isdigit(s[0])){
            op.push_back(s[0]);
            s.erase(s.begin()+0);
            helper(s, op, v);
            return;
        }
    
        string op1 = op;
        string op2 = op;
        if (islower(s[0])) op1.push_back(toupper(s[0]));
        else op1.push_back(tolower(s[0]));
        op2.push_back(s[0]);
        s.erase(s.begin()+0);
        helper(s, op1, v);
        helper(s, op2, v);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> v;
        string op = "";
        helper(s, op, v);
        return v;
    }
};