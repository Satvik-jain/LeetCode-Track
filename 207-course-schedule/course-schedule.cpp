class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto i : pre){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> topo;
        vector<int> indegree(n, 0);
        for (vector<int> i : adj){
            for (int j : i){
                indegree[j]++;
            }
        }
        stack<int> st;
        for(int i = 0; i < n; i++){
            if (indegree[i] == 0){
                st.push(i);
                topo.push_back(i);
            }
        }
        while(!st.empty()){
            int i = st.top(); st.pop();
            for(int j : adj[i]){
                indegree[j]--;
                if (indegree[j] == 0){
                    topo.push_back(j);
                    st.push(j);
                }
            }
        }
        return (topo.size() == n);
    }
};