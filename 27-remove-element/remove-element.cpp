class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == val) nums[i] = INT_MAX;
            else k++;
        }
       sort(nums.begin(), nums.end());
       return k; 
    }
};