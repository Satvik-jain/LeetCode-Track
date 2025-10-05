class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int>& topo, vector<int>& vis, int i, int & cycle){
        vis[i] = 2;
        for (int j : adj[i]){
            if (vis[j] == 2){
                return false;
            }
            if(!vis[j]){
                if (!dfs(adj, topo, vis, j, cycle)) return false;
            }
        }
        vis[i] = 1;
        topo.push_back(i);
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto i : pre){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> topo;
        vector<int> vis(n, 0);
        int cycle = 0;
        for (int i = 0; i < n; i++){
            if(!vis[i]){
                if (!dfs(adj, topo, vis, i, cycle)) return false;
            }
        }
        return true;
    }
};