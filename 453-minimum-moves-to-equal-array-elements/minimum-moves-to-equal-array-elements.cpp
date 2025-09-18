class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mine = *min_element(nums.begin(), nums.end());
        for (int i : nums){
            ans+=(i-mine);
        }
        return ans;
    }
};