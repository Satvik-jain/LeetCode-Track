class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> adj[n];
        for(int i = 0; i < graph.size(); i++){
            for (int j = 0; j < graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        vector <int> indegree(n,0);
        for (int i = 0; i<n; i++){
            indegree[i] = graph[i].size();
        }
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) q.push(i);
        }
        vector <int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for (int i: adj[top]){
                indegree[i]--;
                if (!indegree[i]){
                    q.push(i);
                }
            }

        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};