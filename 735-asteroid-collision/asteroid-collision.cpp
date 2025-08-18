class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for (int i = n-1; i >= 0; i--){
            if (arr[i] < 0){
                st.push(arr[i]);
                continue;
            }
            if (st.empty()){
                ans.push_back(arr[i]);
                continue;
            }
            while(!st.empty() && abs(st.top()) <= arr[i]){
                if (abs(st.top()) < arr[i]){
                    st.pop();
                    if (st.empty()){
                        ans.push_back(arr[i]);
                        // cout << arr[i];
                    }
                }
                else if (abs(st.top()) == arr[i]){
                    st.pop();
                    break;
                }
            }
        }
        int m = ans.size();
        if (!st.empty()){
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin()+m, ans.end());
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};