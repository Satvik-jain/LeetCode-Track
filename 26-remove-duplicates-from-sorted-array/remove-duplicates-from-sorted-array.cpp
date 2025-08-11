class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp = nums[0];
        int i = 1;
        int j = 1;
        int n = nums.size();
        while(j < n){
            if (temp == nums[j]){
                j++;
            }
            else {
                temp = nums[j];
                nums[i] = nums[j];
                i++; j++;
            }
        }
        return i;
    }
};