class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int n, vector<vector<int>>& dp, int & sum){
        if (i == n && target == 0) return 1;
        if (i == n) return 0;
        if (target > sum || target < -sum) return 0;

        if (dp[i][sum+target]!=-1) return dp[i][sum+target];
        int tot = 0;
        tot += helper(nums, target-nums[i], i+1, n, dp, sum) +
                helper(nums, target+nums[i], i+1, n, dp, sum);
        return dp[i][sum+target] = tot; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+sum+1, -1));
        return helper(nums, target, 0, nums.size(), dp, sum);
    }
};