class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 1) return false;
        unordered_map<char, char> mpp;
        mpp[')'] = '('; mpp['}'] = '{'; mpp[']'] = '['; 
        stack<char> st;
        for (int i = 0; i < s.length() ; i++){
            if (st.empty()){
                st.push(s[i]);
                continue;
            }
            char temp = st.top();
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (temp == mpp[s[i]]){
                    st.pop();
                    continue;
                }
                else return false;
            }
            st.push(s[i]);
        }
        cout << "YES";
        return (st.empty()) ? true:false;
    }
};