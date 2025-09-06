class Solution {
public:
    bool dfs(vector<vector<int>> &adj, int i, vector<int>& vis, vector<int> &ans, vector<int>& cycle){
        vis[i] = 1;
        for (int j : adj[i]){
            if (!vis[j]) {if(dfs(adj, j, vis, ans, cycle)){
                cycle[i] = 1;
                return true;
            }}
            else if(vis[j]==1){
                cycle[i] = 1;
                return true;
            }
        }
        vis[i] = 2;
        if(cycle[i] == 0)ans.push_back(i);
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0), cycle(n, 0);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if (!vis[i]){
                dfs(adj, i, vis, ans, cycle);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};