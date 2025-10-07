class Solution {
public:
    void helper(vector<int>& cand, int t, vector<vector<int>>& ans, int idx, vector<int>& v){
        if (t == 0){
            ans.push_back(v);
            return;
        }
        if (idx >= cand.size()) return;
        if (t < 0) return;
        if (cand[idx] <= t){
            v.push_back(cand[idx]);
            helper(cand, t-cand[idx], ans, idx, v);
            v.pop_back();
        }
        helper(cand, t, ans, idx+1, v);
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> v;
        helper(cand, t, ans, 0, v);
        return ans;
    }
};