class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        queue<int> q;
        vector<int> vis(V, -1);
        int color = 0;
        for (int k = 0; k < V; k++){
            if (vis[k] == -1){
                vis[k] = color;
                q.push(k);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for (int i : graph[node]){
                        if (vis[i]==-1){
                            vis[i] = !vis[node];
                            q.push(i);
                        }
                        else if (vis[i] != -1){
                            if (vis[node] == vis[i]) return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};