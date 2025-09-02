class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int n = j+1;
        int next_el, prev_el;
        while(i <= j){
            int mid = (i+j)/2;
            int next = mid+1;
            int prev = mid-1;

            if (next==n) next_el = INT_MIN;
            else  next_el = nums[next];
            if (prev==-1) prev_el = INT_MIN;
            else  prev_el = nums[prev];

            if (nums[mid] > prev_el && nums[mid] > next_el) return mid;
            else if (prev_el > nums[mid]) j = mid-1;
            else i = mid+1;
        }
        return 0;
    }
};