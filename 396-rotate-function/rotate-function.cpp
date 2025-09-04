class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0;
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum+=nums[i];
            f0+=i*nums[i];
        }
        int pre_f = f0;
        for (int i = n-1; i >= 0; i--){
            f0 = max(f0, pre_f+sum-n*nums[i]);
            pre_f = pre_f+sum-n*nums[i];
        }
        return f0;
    }
};