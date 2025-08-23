class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int> &v, vector<int> &hash){
        if (v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (!hash[i]){
                hash[i] = 1;
                v.push_back(nums[i]);
                helper(ans, nums, v, hash);
                hash[i] = 0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<int> hash(nums.size(), 0);
        helper(ans ,nums ,v ,hash);
        return ans;
    }
};