class Solution {
  public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        using intP = tuple<int, int, int>;
        priority_queue<intP, vector<intP>, greater<intP>> q;
        vector<vector<int>> ans;
        set<pair<int, int>> s;
        q.push({a[0]+b[0], 0, 0});
        s.insert({0, 0});
        while(k-- && !q.empty()){
            auto [sum, i, j] = q.top(); q.pop();
            ans.push_back({a[i], b[j]});
            if (i+1<a.size() && !s.count({i+1, j})){
                q.push({a[i+1] + b[j], i+1, j});
                s.insert({i+1, j});
            }
            if(j+1 < b.size() && !s.count({i, j+1})){
                q.push({a[i]+b[j+1], i, j+1});
                s.insert({i, j+1});
            }
        }
        return ans;
    }
};