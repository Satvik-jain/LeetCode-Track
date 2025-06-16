class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector <int> adj[n];
        queue <int> q;
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(n, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if (indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans++;
            for (int i : adj[top]){
                indegree[i]--;
                if (indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if (ans == n) return true;
        else return false;
    }
};