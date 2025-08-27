class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> temp;
        unordered_map<string, vector<int>> mpp;
        for(int i = 0; i < strs.size(); i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            mpp[str].push_back(i);
        }
        for(auto i : mpp){
            temp.clear();
            for (int j : i.second){
                temp.push_back(strs[j]);
            }
            ans.push_back(move(temp));
        }
        return ans;
    }
};