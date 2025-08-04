class Solution {
public:
    int helper(int index, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if (index >= n-1){
            return 0;
        }
        if (dp[index] != -1) return dp[index];
        int mine = 1e9;
        for (int i = 1; i<=nums[index]; i++){
            mine = min(mine, 1+helper(index+i, nums, dp));
        }
        return dp[index] = mine;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};