class Solution {
public:
    void helper(vector<int> &nums, int idx,vector<int> &v, set<vector<int>>& s){
        if (idx == nums.size()){
            s.insert(v);
            return;
        }
        helper(nums, idx+1, v, s);
        v.push_back(nums[idx]);
        helper(nums, idx+1, v, s);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<int> v;
        sort(nums.begin(), nums.end());
        helper(nums, 0, v, s);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};