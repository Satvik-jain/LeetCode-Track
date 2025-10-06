class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int n = j+1;
        int res = INT_MAX;
        while(i <= j){
            int mid = (i+j)/2;
            if (nums[i] <= nums[mid]){
                res = min(nums[i], res);
                i = mid+1;
            }
            else {
                res = min(nums[mid], res);
                j = mid-1;
            }
        }
        return res;
    }
};