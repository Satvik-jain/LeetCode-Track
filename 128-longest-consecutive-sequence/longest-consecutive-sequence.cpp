class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int temp = 1;
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return 1;
        for (int i = 0; i < n-1; i++){
            while(i < n-1 && nums[i] == nums[i+1]) i++;
            if (i < n-1 && nums[i] == nums[i+1] - 1) temp++;
            else temp = 1;
            ans = max(ans, temp);
        }
        return ans;
    }
};