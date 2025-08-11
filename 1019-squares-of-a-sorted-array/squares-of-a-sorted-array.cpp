class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        int index = r;
        vector<int> res(r+1, 0);
        while(l <= r){
            if (abs(nums[l]) < abs(nums[r])){
                res[index] = nums[r] * nums[r];
                r--;
            }
            else {
                res[index] = nums[l] * nums[l];
                l++;
            }
            index--;
        }
        return res;
    }
};