class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = INT_MIN;

        int n = heights.size();

        vector<int> nse;
        vector<int> pse;

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                pse.push_back(-1);
            } else {
                pse.push_back(st.top());
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                nse.push_back(n);
            } else {
                nse.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nse.begin(), nse.end());

        for(int  i = 0; i < n; i++){
            cout << (nse[i]-pse[i]-1)*heights[i] << endl;
            ans = max(ans, (nse[i]-pse[i]-1)*heights[i]);
        }

        return ans;
    }
};