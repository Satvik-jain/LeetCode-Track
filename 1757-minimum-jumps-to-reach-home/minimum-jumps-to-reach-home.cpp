class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        vector<int> cant_jump(6000, 0);
        for (int i : forbidden) cant_jump[i] = 1;
        if (cant_jump[a] == 1) return -1;
        if(a==x) return 1;
        using P = pair<int, pair<int, int>>;
        queue<P> q;
        vector<vector<int>> vis(6000, vector<int>(2, 0));
        q.push({0, {0, 0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int pos = temp.second.first;
            int jump = temp.first;
            int is_back = temp.second.second;
            if (pos==x) return jump;
            if (pos+a < 6000 && !vis[pos+a][0] && !cant_jump[pos+a]){
                vis[pos+a][0] = 1;
                q.push({jump+1, {pos+a, 0}});
            }
            if ((pos-b >= 0 && !cant_jump[pos-b]) && !is_back && !vis[pos-b][1]){
                vis[pos-b][1] = 1;
                q.push({jump+1, {pos-b, 1}});
            }
        }
        return -1;
    }
};