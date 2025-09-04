class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = INT_MAX;
        int ans;
        for (int i = 0; i < n; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            int desired = target - nums[i];
            int a = i+1, b = n-1;
            while(a < b){
                int sum = (nums[a] + nums[b] + nums[i]);
                if (abs(target-sum) < prev){
                    ans = sum;
                    prev = abs(target-sum);
                }
                if(nums[a]+nums[b] > desired) b--;
                else a++;
            }
        }
        return ans;
    }
};