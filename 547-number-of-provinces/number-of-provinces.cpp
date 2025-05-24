class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<int>& vis, int i){
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            vis[front]++;
            if (adj[front].size()){
                for(auto it: adj[front]){
                    if (vis[it] == 0){
                        vis[it]++;
                        q.push(it);
                    }
                }
        }
        }
        return true;
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[i][j] == 1 && i != j)
                    adj[i].push_back(j);
            }
        }

        int ans = 0;

        vector<int> vis(n, 0);
        
        
        for (int i=0; i<n; i++){

            if ((vis[i]==0) && bfs(adj, vis, i)) ans++;
        }
        return ans;
    }
};