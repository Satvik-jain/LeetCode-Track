class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        using ll = long long; using P = pair<ll, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, 0});
        vector<ll> dis(n, LLONG_MAX);
        dis[0] = 0;
        vector<ll> vis(n, 0);
        vis[0] = 1;
        while(!q.empty()){
            ll d = q.top().first;
            int node = q.top().second;
            q.pop();
            if (d > dis[node]) continue;
            for (auto i : adj[node]){
                ll new_d = d+i.second;
                ll new_node = i.first;
                if (new_d < dis[new_node]){
                    dis[new_node] = new_d;
                    q.push({new_d, new_node});
                    vis[new_node] = vis[node];
                }
                else if (new_d == dis[new_node]){
                    vis[new_node] = (vis[new_node]+vis[node])%(int)(1e9+7);
                }
            }
        }
        return vis[n-1]%(int)(1e9+7);
    }
};