class Solution {
private:
    bool dfs(vector<int>&vis, int i, stack<int>&s, vector<int> adj[]){
        vis[i] = 1;
        for (auto j: adj[i]){
            if (vis[j] == -1) dfs(vis, j, s, adj);
            if (vis[j] == 1) return true;
        }
        vis[i] = 2;
        s.push(i);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack<int> s;
        vector<int> vis(numCourses, -1);
        for(int i = 0; i < numCourses; i++){
            if (vis[i] == -1) 
            {
                if(dfs(vis, i, s, adj)){
                    return {};
                }
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};