class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i : nums){
            mpp[i]++;
        }
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        for(auto it : mpp){
            q.push({it.second, it.first});
            if (q.size() > k) q.pop();
        }
        // cout << q.size();
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().second); q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};