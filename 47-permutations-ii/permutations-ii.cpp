class Solution {
public:
    void helper(set<vector<int>>& ans, vector<int>& v, vector<int>& nums, vector<int>& hash){
        if (v.size() == nums.size()){
            ans.insert(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if (!hash[i]){
                v.push_back(nums[i]);
                hash[i] = 1;
                helper(ans, v, nums, hash);
                v.pop_back();
                hash[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> v, hash(n, 0);
        sort(nums.begin(), nums.end());
        helper(ans, v, nums, hash);
        vector<vector<int>> f_ans(ans.begin(), ans.end());
        return f_ans;
    }
};