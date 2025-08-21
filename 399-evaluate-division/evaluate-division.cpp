class Solution {
public:
    double bfs(string st, string end, unordered_map<string, vector<pair<string, double>>> &mpp){
        queue<pair<string, double>> q;
        set<string> s;
        if (st == end) return 1;
        q.push({st, 1});
        s.insert(st);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if (temp.first == end) return temp.second;
            for (auto i : mpp[temp.first]){
                if (s.find(i.first) == s.end()){
                    if (i.first == end) return temp.second*i.second;
                    q.push({i.first, i.second*temp.second});
                    s.insert(i.first);
                } 
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string, vector<pair<string, double>>> mpp;
        for(int i = 0; i < n; i++){
            mpp[equations[i][0]].push_back({equations[i][1], values[i]});
            mpp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> ans;
        for (auto i : queries){
            string st = i[0], end = i[1];
            if (mpp.find(st) == mpp.end() || mpp.find(end) == mpp.end()) ans.push_back(-1);
            else ans.push_back(bfs(st, end, mpp));
        }
        return ans;
    }
};