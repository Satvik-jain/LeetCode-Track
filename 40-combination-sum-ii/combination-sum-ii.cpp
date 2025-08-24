class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx, vector<vector<int>> & ans, vector<int>& v, vector<int>& hash){
        if (target == 0){
            ans.push_back(v);
            return;
        }
        while (idx < candidates.size() && idx > 0 && candidates[idx-1] <= target && hash[candidates[idx-1]] == 0 && candidates[idx] == candidates[idx-1]){
            idx++;
        }
        if (idx >= candidates.size() || target < 0) return;
        if (candidates[idx] > target) return;
        cout << idx;
        
        // cout << candidates[idx] << endl;
        if (idx < candidates.size()){
            v.push_back(candidates[idx]);
            hash[candidates[idx]] = 1; 
            helper(candidates, target - candidates[idx], idx+1, ans, v, hash);
            v.pop_back();
            hash[candidates[idx]] = 0;
            helper(candidates, target, idx+1, ans, v, hash);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        vector<int> hash(target+1, 0);
        helper(candidates, target, 0, ans, v, hash);
        return ans;
    }
};