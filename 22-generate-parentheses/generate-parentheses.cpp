class Solution {
public:

    void helper(vector<string>& v, string op, int o, int c){
        // cout << o << " " << c << endl;
        if ((o == c) && (c!=0)){
            op.push_back('(');
            helper(v, op, o-1, c);
            return;
        }
        if(c==0){
            v.push_back(op); 
            return;
        }
        string op1 = op;
        string op2 = op;
        if(o!=0){
            op1.push_back('(');
            helper(v, op1, o-1, c);
        }
        op2.push_back(')');
        helper(v, op2, o, c-1);  
    }

    vector<string> generateParenthesis(int n) {
        int o = n, c = n;
        string op = "";
        vector <string> v;
        helper(v, op, o, c);
        return v;
    }
};