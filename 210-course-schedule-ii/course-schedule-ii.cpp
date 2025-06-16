class Solution {
private:
    // bool dfs(vector<int>&vis, int i, stack<int>&s, vector<int> adj[]){
    //     vis[i] = 1;
    //     for (auto j: adj[i]){
    //         if (vis[j] == -1) dfs(vis, j, s, adj);
    //         if (vis[j] == 1) return true;
    //     }
    //     vis[i] = 2;
    //     s.push(i);
    //     return false;
    // }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        for (int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        
        for(auto i: prerequisites){
            indegree[i[0]]++;
        }

        for (int i = 0; i < numCourses; i++){
            if (!indegree[i]) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            ans.push_back(top); 
            q.pop();
            for (auto i: adj[top]){
                indegree[i]--;
                if (indegree[i] == 0){
                    q.push(i);
                }
            }
            
        }
        if (ans.size() == numCourses) return ans;
        else return {};

    }
};