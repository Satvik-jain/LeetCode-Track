class Solution {
public:
    int helper(vector<int>& nums, int target, int i, int n){
        if (i == n && target == 0) return 1;
        if (i == n) return 0;
        int tot = 0;
        tot += helper(nums, target-nums[i], i+1, n) +
                helper(nums, target+nums[i], i+1, n);
        return tot; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size());
    }
};