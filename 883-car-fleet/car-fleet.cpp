class Solution {
public:
    bool static comp(const pair<int, double> &a, const pair<int, double> &b){
        return a.first < b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int , double>> v;
        int n = position.size();
        for (int i = 0; i < n; i++){
            double time = (double)(target - position[i])/(double)speed[i];
            v.push_back({position[i], (time)});
        }
        sort(v.begin(), v.end(), comp);
        int ans = 0;
        stack<double> st;
        for (int i = n-1 ; i >= 0; i--){
            while(st.size() && st.top() < v[i].second) st.pop();
            if (!st.size()) ans++;
            st.push(v[i].second);
        }
        return ans;
    }
};