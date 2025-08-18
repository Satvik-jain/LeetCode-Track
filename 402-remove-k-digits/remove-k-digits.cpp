class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        if (k>=n) return "0";
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && k && nums[i] < st.top()){
                k--;
                st.pop();
            }
            st.push(nums[i]);
        }
        string s;
        while (!st.empty()) {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        if (k>0) s = s.substr(0, s.size()-k);
        cout << s;
        int i;
        bool zeros = false, is_zero = false;
        for(i = 0; i < s.length(); i++){
            if (s[i]!='0'){
                zeros = true;
                break;
            }
            else{
                is_zero = true;
            }
        }
         
        if (!zeros && is_zero) {
            return "0";
        }
        if (zeros) s = s.substr(i);
        return (s.size())?s:"0";
    }
};