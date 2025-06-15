class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, vector<int>&v, vector<int>& pv){
        v[i] = 1;
        pv[i] = 1;
        bool cycle = false;
        for (auto j: graph[i]){
            if (v[j] == -1){
                if (dfs(graph, j, v, pv)) cycle = true;
            }
            else{
                if(pv[j] == 1) cycle =true;
            }
        }
        if (!cycle) pv[i] = !pv[i];
        return cycle;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> v(V,-1);
        vector<int> pv(V,-1);

        for (int i = 0; i < V; i++){
            if (v[i] == -1){
                dfs(graph, i, v, pv);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++){
            if (pv[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};