class Solution {
public:
    void helper(vector<int> &nums, int idx,vector<int> &v, vector<vector<int>> &ans){
        if (idx == nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        helper(nums, idx+1, v, ans);
        v.pop_back();
        while(idx+1 < nums.size() && nums[idx] == nums[idx+1]) idx++;
        helper(nums, idx+1, v, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        helper(nums, 0, v, ans);
        return ans;
    }
};