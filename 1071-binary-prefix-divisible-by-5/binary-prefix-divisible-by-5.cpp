class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num = 0;
        vector<bool> ans;
        for (int i: nums){
            num = (2*num)%5 + i;
            if (num%5) ans.push_back(false);
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};