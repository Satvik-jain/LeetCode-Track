class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        int jump = 0;
        int end = 0;

        for (int i = 0; i < n - 1; i++) {
            maxInd = max(maxInd, i + nums[i]);
            if (i == end) {
                jump++;
                end = maxInd;
            }
        }

        return jump;
    }
};