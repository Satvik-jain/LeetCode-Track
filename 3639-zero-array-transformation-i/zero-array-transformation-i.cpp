class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector <int> hash(n, 0);

        for (auto i : queries){
            hash[i[0]]++;
            if (i[1]+1 < n)hash[i[1]+1]--;
        }
        int count = 0;
        
        for (int i = 0; i < n; i++){
                count+=hash[i];
                nums[i] = max(0, nums[i]-count);
        }
        for (auto i : nums){
            if (i!=0) return false;
        }
        return true;
    }
};