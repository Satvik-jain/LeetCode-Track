class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<int> color(graph.size(), 0);
        int n = graph.size();
        for (int j = 0; j < n; j++){
            if (vis[j] == 0){
queue<int> q;
            q.push(j);
            vis[j] = 1;
            color[j] = 0;
            while(!q.empty()){
                int at = q.front();
                q.pop();
                for(int i : graph[at]){
                    if (vis[i] == 0){
                        vis[i] = 1;
                        q.push(i);
                        color[i] = !color[at];
                    }
                    else{
                        if (color[i] == color[at]) return false;
                    }
                }
            }
            }
            
            
        }
        return true;
    }
};