
class Solution {
public:
    int helper(vector<int>& nums, int rem, int i, int sum, vector<vector<int>>& dp){
        if (i == nums.size()){
            if (sum%3 == 0 && i == nums.size()) return 0;
            return -1e9;
        }
        if (dp[i][sum%3] != -1) return dp[i][sum%3];

        int taken = INT_MIN, not_taken;

        taken = nums[i] + helper(nums, rem, i+1, sum+nums[i], dp);
        not_taken = helper(nums, rem, i+1, sum, dp);

        return dp[i][sum%3] = max(taken, not_taken);
    }
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(), 0);
        int rem = sum%3;
        vector<vector<int>> dp(nums.size(), vector<int>(3, -1));

        int ans = helper(nums, rem, 0, 0, dp);
        
        return max(0, ans);
    }
};