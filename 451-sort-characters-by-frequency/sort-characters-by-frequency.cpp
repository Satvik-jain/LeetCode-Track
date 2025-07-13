class Solution {
public:
    string frequencySort(string s) {
        using P = pair<int, char>;
        priority_queue<P> q;
        vector<int> v(26, 0);
        unordered_map<char, int> mpp;
        for(auto i: s){
            mpp[i]++;
        }
        for (auto i : mpp){
            q.push({i.second, i.first});
        }
        string ans;
        while(!q.empty()){
            int temp = q.top().first;
            while(temp--) ans+=q.top().second;
            q.pop();
        }
        return ans;
    }
};