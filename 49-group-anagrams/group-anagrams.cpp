class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for (int i = 0; i < strs.size(); i++){
            string og = strs[i];
            string sorted = og;
            sort(sorted.begin(), sorted.end());
            mpp[sorted].push_back(og);
        }
        vector<vector<string>> ans;
        for (auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};