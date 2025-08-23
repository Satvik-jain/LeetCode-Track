class Solution {
public:
    void helper(vector<int> &v, vector<vector<int>> &ans, int& n, int& k){
        if (v.size() == k){
            ans.push_back(v);
            return;
        }
        int temp = (v.size() == 0)?1:v[v.size()-1]+1;
        for (int i = temp; i < n+1; i++){
            v.push_back(i);
            helper(v, ans, n, k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> ans;
        helper(v, ans, n, k);
        return ans;
    }
};