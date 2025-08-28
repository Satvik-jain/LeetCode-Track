class Solution {
public:
    int helper(vector<int> & nums, int indx, int last, vector<vector<int>> &dp){
        if (indx == nums.size()){
            return 0;
        }
        
        if (dp[indx][last+1] != -1) return dp[indx][last+1];

        int temp = helper(nums, indx+1, last, dp);

        if (last == -1 || nums[last] < nums[indx]){
            return dp[indx][last+1]=max(1+helper(nums, indx+1, indx, dp), temp);
        }

        return dp[indx][last+1]=temp;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return helper(nums, 0, -1, dp);
    }
};