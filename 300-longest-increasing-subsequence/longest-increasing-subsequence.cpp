class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i = 0; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                   if (nums[j] < nums[i]){
                        dp[i] = max(1+dp[j], dp[i]);
                   }
            }
        }
        return 1+*max_element(dp.begin(), dp.end());
    }
}; 