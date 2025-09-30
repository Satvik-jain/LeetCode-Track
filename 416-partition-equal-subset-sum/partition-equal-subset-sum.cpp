class Solution {
public:
    bool helper(vector<int>& nums, int n, int sum, vector<vector<int>> &dp, int i){
        if (sum <= 0) return (sum==0);
        if (i >= n) return false;

        if (dp[i][sum]!=-1) return dp[i][sum];

        bool take = false, not_take = false;

        if (nums[i] <= sum) take = helper(nums, n, sum-nums[i], dp, i+1);

        not_take = helper(nums, n, sum, dp, i+1);

        return dp[i][sum] = (take || not_take);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0) return false;
        vector<vector<int>> dp(n+1, vector<int>((sum/2)+1, -1));
        return helper(nums, n, sum/2, dp, 0);
    }
};