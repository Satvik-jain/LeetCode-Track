class Solution {
public:
    int MAH(vector<int>& heights) {
        int ans = INT_MIN;
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);

        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }

        for(int  i = 0; i < n; i++){
            cout << (nse[i]-pse[i]-1)*heights[i] << endl;
            ans = max(ans, (nse[i]-pse[i]-1)*heights[i]);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            int preSum = 0;
            for(int j = 0; j < n; j++){
                if (matrix[j][i] == '1'){
                    preSum++;
                    grid[j][i] = preSum;
                }
                else preSum = 0;
            }
        }

        int maxe = 0;
        for (int i = 0; i < n; i++){
            maxe = max(maxe, MAH(grid[i]));
        }

        return maxe;
    }
};














