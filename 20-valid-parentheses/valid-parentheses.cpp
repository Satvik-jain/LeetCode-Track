class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1) return false;

        stack<char> st;
        unordered_map<char, char> mpp;

        mpp[')'] = '('; mpp['}'] = '{'; mpp[']'] = '['; 

        for (auto i : s){
            if (i=='['||i=='{'||i=='('){
                st.push(i);
            }
            else{
                if (st.size() && st.top() == mpp[i]){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};