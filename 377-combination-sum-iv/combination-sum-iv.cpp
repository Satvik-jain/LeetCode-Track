class Solution {
public:
    int helper(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        if (target == 0){
            return 1;
        }
        if (index == nums.size() || target < 0) return 0;
        if (dp[index][target] != -1) return dp[index][target];
        
        int ways=0;
        for (int i = 0; i < nums.size(); i++){
            ways+=helper(nums, i, target-nums[i], dp);
        }

        return dp[index][target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {

        vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        return helper(nums, 0, target, dp);
    }
};