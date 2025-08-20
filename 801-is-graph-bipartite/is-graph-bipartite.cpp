class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, vector<int> &vis, bool sign){
        vis[i] = sign;
        for(auto j: graph[i]){
            if (vis[j]!=-1){
                if(vis[j]==sign) return false;
            }
            if (vis[j] == -1 && !dfs(graph, j, vis, !sign)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v(n, -1);
        // return dfs(graph, v);
        bool ans=true;
        for(int i = 0; i < graph.size(); i++){
            if (v[i] == -1) ans = dfs(graph, i, v, 1);
            if(!ans) return false;
        }
        return ans;
    }
};