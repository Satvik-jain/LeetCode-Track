class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), -1);
        for(int k = 0; k < graph.size(); k++){
            if (vis[k] == -1){
                vis[0] = k;
                queue<int> q;
                q.push(k);
                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    for(int j: graph[temp]){
                        if (vis[j] == -1){
                            if(!vis[temp]) vis[j] = 1;
                            else vis[j] = 0; 
                            q.push(j);
                        }
                        else{
                            if(vis[j]!=vis[temp]) continue;
                            else return false; 
                        }
                    }
                }
            }
        }
        return true;
    }
};