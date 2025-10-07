class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> & ans, int idx, vector<int> &v){
        if (idx == nums.size()){
            ans.push_back(v); return;
        }
        helper(nums, ans, idx+1, v);
        v.push_back(nums[idx]);
        helper(nums, ans, idx+1, v);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(nums, ans, 0, v);
        return ans;
    }
};