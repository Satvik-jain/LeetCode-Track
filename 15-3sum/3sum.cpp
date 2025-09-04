class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            int a = i+1, b = n-1;
            while(a<b){
                int desired = (0-nums[i]);
                if (nums[a] + nums[b] == desired){
                    ans.push_back({nums[i], nums[a], nums[b]});
                    a++; b--;
                    while(a<b && nums[a] == nums[a-1]) a++;
                    while(a<b && nums[b] == nums[b+1]) b--;
                }
                else if (nums[a] + nums[b] < desired) a++;
                else b--;
            }
        }
        return ans;
    }
};