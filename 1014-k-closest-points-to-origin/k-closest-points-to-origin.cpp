class Solution {
public:
using P = pair<int, int>;
    struct comp{
        bool operator()(P& p1, P& p2){
            return p1.first*p1.first + p1.second*p1.second < p2.first*p2.first + p2.second*p2.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for (auto i : points){
            pq.push({i[0], i[1]});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
     }
};