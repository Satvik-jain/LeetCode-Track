class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int ans = -1;
        while(h>=l){
            int mid = (l+h) * 0.5;
            if (target == nums[mid]){
                ans = mid;
                h = mid - 1;
            }
            else if(target >= nums[mid]) l = mid + 1;
            else h = mid - 1;
        }
        return ans;
    }
};