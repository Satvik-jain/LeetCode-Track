class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++){
            if (i && nums[i]==nums[i-1]) continue;
            int a = i+1, b = n-1;
            while(a<b){
                int target = -nums[i];
                if (nums[a] + nums[b] == target){
                    ans.push_back({nums[i], nums[a], nums[b]});
                    while(a<n-1 && nums[a] == nums[a+1]) a++;
                    while(b>0 && nums[b] == nums[b-1]) b--;
                    a++;
                    b--;
                }
                else if (nums[a] + nums[b] > target){
                    b--;
                }
                else a++;
            }
        }
        return ans;
    }
};