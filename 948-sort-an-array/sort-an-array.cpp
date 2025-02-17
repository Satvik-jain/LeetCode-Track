class Solution {
public:
    void insert(vector<int> &nums, int n){
        
        if ((nums.empty())||(nums.back() <= n))
        {
            nums.push_back(n);
            return;
        }
        int ele = nums.back();
        nums.pop_back();
        insert(nums, n);
        nums.push_back(ele);
    }
    vector<int> sortArray(vector<int>& nums) {
        // if (nums.size()<=1){
        //     return nums;
        // }
        // int ele = nums.back();
        // nums.pop_back();
        // nums = sortArray(nums); 

        // insert(nums, ele);

 
        // return nums;
        sort(nums.begin(), nums.end());
        return nums;
    }
};