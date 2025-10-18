class Solution {
public:
    long long helper(vector<int>& nums, int i, int sign, vector<vector<long long>>& dp){
        if (i >= nums.size()) return 0;
        if (dp[i][sign+1]!=-1) return dp[i][sign+1];
        long long taken = sign*nums[i]+helper(nums, i+1, sign*-1, dp);
        long long not_taken = helper(nums, i+1, sign, dp);
        return dp[i][sign+1] = max(taken, not_taken);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(3, -1));
        return helper(nums, 0, 1, dp);
    }
};