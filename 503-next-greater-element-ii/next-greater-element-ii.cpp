class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> v;
        for (int i = n - 1; i >= 0; i--) {
            st.push(arr[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(arr[i]);
                v.push_back(-1);
                continue;
            }
            int temp = st.top();
            while (temp <= arr[i]) {
                st.pop();
                if (st.empty()) {
                    break;
                }
                temp = st.top();
            }
            if (!st.empty()) {
                v.push_back(st.top());
            } else {
                v.push_back(-1);
            }
            st.push(arr[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};