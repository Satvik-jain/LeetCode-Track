class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int components = 0;
        vector<bool> visited(n, false);

        function<long long(int)> dfs = [&](int u) {
            visited[u] = true;
            long long sum = values[u];

            for (int v : adj[u]) {
                if (!visited[v]) {
                    sum += dfs(v);
                }
            }
            return sum;
        };

        function<long long(int)> dfs2 = [&](int u) {
            visited[u] = true;
            long long sum = values[u];

            vector<int> children;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    children.push_back(v);
                }
            }

            for(int v : children){
                long long child_sum = dfs2(v);
                if(child_sum % k == 0){
                    components++;
                } else {
                    sum += child_sum;
                }
            }

            return sum;
        };

        visited.assign(n, false);
        dfs2(0);
        
        visited.assign(n, false);
        long long total_sum = dfs(0);

        if(total_sum % k == 0)
            return components + 1;
        
        return components;
    }
};