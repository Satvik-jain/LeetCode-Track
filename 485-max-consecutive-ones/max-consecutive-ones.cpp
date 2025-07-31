class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int temp = 0, maxe = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == 1) temp++;
            else{
                temp = 0;
            }
            maxe = max(maxe, temp);
        }
        return maxe;
    }
};