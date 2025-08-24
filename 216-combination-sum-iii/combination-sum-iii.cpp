class Solution {
public:
    void helper(vector<vector<int>>& ans, int start, vector<int>& v, int k, int target){
        if (k < 0 || target < 0) return;
        if (!k && !target){ 
            ans.push_back(v);
            return;
        }
        for (int i = start; i <= 9-k+1; i++){
            v.push_back(i);
            helper(ans, i+1, v, k-1, target-i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> ans;
        helper(ans, 1, v, k, n);
        return ans;        
    }
};