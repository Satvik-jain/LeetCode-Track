class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        int n = nums.size();
        int pivot = -1;
        for (int i = n-1; i >= 1; i--){
            if (nums[i-1] < nums[i]){
                pivot = i-1;
                break;
            }
        }
        if (pivot == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        for (int i = n-1; i >= 0; i--){
            if (nums[pivot] < nums[i]){
                swap(nums[pivot], nums[i]);
                for(auto i : nums){
                }
                break;
            }
        }
        reverse(nums.begin()+pivot+1, nums.end());
    }
};