class Solution {
public:
    int helper(vector<int>& nums, int n, vector<int>& dp, int i){

        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + helper(nums, n, dp, i+2), helper(nums, n, dp, i+1));
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n+1, -1);

        auto dp2 = dp;

        return max(helper(nums, n-1, dp, 0), helper(nums, n, dp2, 1));

    }
};