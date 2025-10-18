class Solution {
public:
    long long helper(vector<int>& nums, int i, int sign, vector<vector<long long>>& dp) {
        if (i == nums.size()) return 0;

        int idx = (sign == 1 ? 0 : 1);
        if (dp[i][idx] != -1) return dp[i][idx];

        long long take = sign * nums[i] + helper(nums, i + 1, -sign, dp);
        long long skip = helper(nums, i + 1, sign, dp);

        return dp[i][idx] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return helper(nums, 0, 1, dp);
    }
};
