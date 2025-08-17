class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> nse, pse;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (st.empty()){
                pse.push_back(-1);
                st.push(i);
            }
            else{
                pse.push_back(st.top());
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()){
                nse.push_back(n);
                st.push(i);
            }
            else{
                nse.push_back(st.top());
                st.push(i);
            }
        }
        reverse(nse.begin(), nse.end());
        for (int i = 0; i < n; i++){
            ans=(ans+(int)((1LL*(i-pse[i])*(nse[i]-i)*arr[i])%((int)1e9+7)))%((int)1e9+7);
        }
        return ans;
    }
};