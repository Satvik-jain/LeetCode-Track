class Solution {
public:
    int t[20001];
    int helper(int i, vector<int>& nums){
        if(i >= nums.size()) return 0;
        if (t[i] != -1) return t[i];
        int curr = nums[i];
        int curr_sum = nums[i];
        int index = i+1;
        

        while(index<nums.size() && nums[index] == curr ){
            index++;
            curr_sum+=curr;
        }
        while(index<nums.size() && nums[index] == curr+1){
            index++;
        }
        return t[i] = max(curr_sum+ helper(index, nums), helper(i+1, nums));
    }
    int deleteAndEarn(vector<int>& nums) {
        int index = 0;
        sort(nums.begin(), nums.end());
        memset(t,-1, sizeof(t));
        return helper(index, nums);
    }
};