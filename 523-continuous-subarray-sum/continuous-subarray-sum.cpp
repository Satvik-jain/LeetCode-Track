class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> mpp;
        mpp[0] = -1;
        int sum = 0; int rem;
        for (int i = 0; i < n; i++){
            sum+=nums[i];
            rem=sum%k;
            if (mpp.find(rem) == mpp.end()){
                mpp[rem] = i;

            }
            else{
                if (i - mpp[rem] >= 2) return true;
            }
        } 
        return false;
    }
};