class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i < j){
            int mid = (i+j)/2;
            // int prev = (mid-1 >= 0) ? nums[mid-1] : INT_MAX;
            // int next = (mid+1 < nums.size()) ? nums[mid+1] : INT_MAX ;
            // if (prev > nums[mid] && nums[mid] < next) return nums[mid];
            if (nums[j] < nums[mid]) i = mid+1;
            else j = mid;
        }
        return nums[i];
    }
};