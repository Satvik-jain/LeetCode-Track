class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 1;
        int curr;
        int prev = nums[1] - nums[0];
        int cnt = (prev == 0) ? 1 : 2;
        for (int i = 2; i < n ; i++){
            curr = nums[i] - nums[i-1];
            if ((curr > 0 && prev <= 0) || (curr < 0 && prev >= 0)){
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};