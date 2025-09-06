class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n, 0);
        vector<int> ans;
        queue<int> q;
        vector<vector<int>> temp(n);
        for (int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++){
                temp[adj[i][j]].push_back(i);
            }
        }
        for(int i=0;i<adj.size();i++){
            indegree[i]+=adj[i].size();
        }
        adj = temp;
        // for (int i : indegree) cout << i;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) {
                ans.push_back(i);q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front(); q.pop();
            for (int i: adj[top]){
                indegree[i]--;
                if (!indegree[i]){
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};