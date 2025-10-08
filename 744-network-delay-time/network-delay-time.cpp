class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int V = n;
        vector<vector<pair<int, int>>> adj(V+1);
        for (const auto &i : times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, k});
        vector<int> dis(V+1, INT_MAX);
        dis[k] = 0;
        while(!q.empty()){
            auto [d, node] = q.top();
            q.pop();
            if (d > dis[node]) continue;
            for (const auto &i : adj[node]){
                if (dis[i.first] > i.second+d){
                    dis[i.first] = i.second+d;
                    q.push({dis[i.first], i.first});
                }
            }
        }
        int maxe = INT_MIN;
        for(int i = 1; i <= V; i++){
            maxe = max(maxe, dis[i]);
        }
        return (maxe == INT_MAX) ? -1 : maxe;
    }
};