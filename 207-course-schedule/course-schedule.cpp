class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int i, vector<int>& vis, vector<int>& path_vis){
        vis[i] = 1; path_vis[i] = 1;
        for (int j : adj[i]){
            if (vis[j] == 0){
                if (dfs(adj, j, vis, path_vis)) return true;
            }
            if (path_vis[j] == 1) return true;
        }
        path_vis[i] = 0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto i : pre){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0);
        vector<int> path_vis(n, 0);

        for(int i = 0; i < n; i++){
            if (!vis[i]){
                if (dfs(adj, i, vis, path_vis)) return false;
            }
        } 
        
        return true;
    }
};