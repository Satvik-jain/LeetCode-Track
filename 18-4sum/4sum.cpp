class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i = 0; i<n; i++){
            for (int j = i+1; j < n; j++){
                long long desired = (long long)target - nums[i] - nums[j];
                int a = j+1, b = n-1;
                while(a<b){
                    if(nums[a] + nums[b] == desired){
                        s.insert({nums[i], nums[j], nums[a], nums[b]});
                        a++; b--;
                    }
                    else if (nums[a] + nums[b] < desired) a++;
                    else b--;
                }
            }
        }
        for (auto i : s){
            ans.push_back(i);
        }
        return ans;
    }
};