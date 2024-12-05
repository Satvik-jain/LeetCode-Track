class Solution {
private:
    void bfs(vector<int>& vis, int i, vector<vector<int>>& adj)
    {
        queue <int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for (auto it : adj[temp]){
                if (!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& am) {
        int n = am.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i!=j && am[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n,0);
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                bfs(vis, i, adj);
                ans++;
            }
        }
        return ans;
    }
};