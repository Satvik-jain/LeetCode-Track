class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int n, int i){
        if(i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int a = INT_MIN;
        if (i+1 < n) a = nums[i+1] + helper(nums, dp, n, i+3);
        return dp[i] = max(nums[i] + helper(nums, dp, n, i+2), a);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n+1, -1);
        return max(nums[0] + helper(nums, dp, n, 2), nums[1] + helper(nums, dp, n, 3));
    }
};