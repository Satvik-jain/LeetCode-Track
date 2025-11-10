class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1), ans2(n, 1);
        for (int i = 1; i < nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        for (int i = n-2; i >= 0; i--){
            ans2[i] = ans2[i+1] * nums[i+1];
        }
        for (int i = 0; i < n; i++) ans[i] = ans[i]*ans2[i];
        return ans;
    }
};