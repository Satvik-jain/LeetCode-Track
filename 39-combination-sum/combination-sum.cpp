class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx, vector<vector<int>> & ans, vector<int>& v){
        if (target == 0){
            ans.push_back(v);
            return;
        }
        if (idx >= candidates.size() || target < 0) return;
        if (candidates[idx] > target) return;
        helper(candidates, target, idx+1, ans, v);
        v.push_back(candidates[idx]);
        helper(candidates, target - candidates[idx], idx, ans, v);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, ans, v);
        return ans;
    }
};