class Solution {
public:
    int f(vector<int>& nums, vector<vector<int>>& dp, int curr, int prev){
        int n = nums.size();
        // cout << "l : " << l << ", prev: " << prev << endl;
        if(curr == n) return 0;
        if (dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        // int taken = INT_MIN, not_taken = INT_MIN;
        if (prev == -1 || nums[curr] > nums[prev]){
            return dp[curr][prev+1] = max(1+f(nums, dp, curr+1, curr), f(nums, dp, curr+1, prev));
        }
        else{
            return dp[curr][prev+1] = f(nums, dp, curr+1, prev);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(nums, dp, 0, -1);
    }
};