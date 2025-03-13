class Solution {
public:
    void helper(vector<int> op, vector<vector<int>> &v, vector<int> nums){
        if (nums.empty()){
            v.push_back(op);
            return;
        }
        vector<int> o1 = op;
        vector<int> o2 = op;
        o1.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        helper(o1, v, nums);
        helper(o2, v, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> op;
        vector<vector<int>> v;
        helper(op, v, nums);
        return v;
	}
};