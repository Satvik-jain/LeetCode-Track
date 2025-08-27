class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return false;
        int f=INT_MAX, s=f;  //  count = 1;

        for (int i = 0; i < n; i++){
            if (f >= nums[i]){
                f = nums[i];
            }
            else if (s >= nums[i]){
                s = nums[i];
            }
            else return true;
        }
        return false;
    }
};