class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for (; i < n; i++) {
            sum += nums[i];
            if (mpp.count(sum - k)) cnt += mpp[sum - k];
            mpp[sum]++;
        }
        return cnt;
    }
};