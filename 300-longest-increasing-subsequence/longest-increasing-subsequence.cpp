class Solution {
  public:
    int lengthOfLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxe = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (arr[i] > arr[j] && 1+dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxe = max(maxe, dp[i]);
        }
        return maxe;
    }
};