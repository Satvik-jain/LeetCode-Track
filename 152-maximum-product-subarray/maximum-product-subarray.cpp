class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0], maxe = res, mine = res; 
        for (int i = 1; i < n; i++){
            if(nums[i] < 0){
                swap(maxe, mine);
            }
            maxe = max(nums[i], maxe * nums[i]);
            mine = min(nums[i], mine * nums[i]);
            res = max(res, maxe);
        }
        return res;
    }
};