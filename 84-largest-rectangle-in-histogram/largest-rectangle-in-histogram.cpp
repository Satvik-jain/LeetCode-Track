class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n), pse(n);
        stack<pair<int, int>> st;
        for (int i = n-1; i >= 0; i--){
            while(st.size() && st.top().first >= heights[i]) st.pop();
            if (st.size()) nse[i] = st.top().second;
            else nse[i] = n;
            st.push({heights[i], i});
        }
        while(st.size()) st.pop();
        for (int i = 0; i < n; i++){
            while(st.size() && st.top().first >= heights[i]) st.pop();
            if (st.size()) pse[i] = st.top().second;
            else pse[i] = -1;
            st.push({heights[i], i});
        }
        int maxe = INT_MIN;
        for (int i = 0; i < n; i++){
            maxe = max(maxe, (nse[i] - pse[i] - 1)*heights[i]);
            // cout << nse[i] << " " << pse[i] << " " << maxe << endl;
        }
        return maxe;
    }
};