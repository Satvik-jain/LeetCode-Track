class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int> hash, int &n, int l){
        if (l == n){
            return 1;
        }
        int taken = 0;
        for (int j = 0; j < n; j++){
            if (hash[j]) continue;
            if (i!=-1){
                int root = sqrt(nums[i] + nums[j]);
                if (root*root == nums[i] + nums[j]){
                    hash[j] = 1;
                    taken += helper(nums, j, hash, n, l+1);
                    hash[j] = 0;
                }
            }
            else{
                hash[j] = 1;
                taken += helper(nums, j, hash, n, l+1);
                hash[j] = 0;
            }
            while(j+1 < n && nums[j] == nums[j+1]) j++;
        }
        return taken;
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> hash(nums.size(), 0);
        int n = nums.size();
        
        return helper(nums, -1, hash, n, 0);
    }
};