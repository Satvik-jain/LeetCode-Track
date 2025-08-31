class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = nums[0];
        for(int num : nums){
            if (!count) ele = num;
            if (num == ele){
                count++;
            }
            else count--;
        }
        return ele;
    }
};