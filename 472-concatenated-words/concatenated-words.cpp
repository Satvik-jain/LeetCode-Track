class Solution {
public:
    bool helper(unordered_map<string, int> &mpp, int index, string word, int k, vector<int>& dp){
        if (index == word.length()){
            return (k>1);
        }
        if (dp[index] != -1) return dp[index];
        string new_w = "";
        for (int i = index; i < word.size(); i++){
            new_w+=word[i];
            if (mpp[new_w] == 1){
                if (helper(mpp, i+1, word, k+1, dp)) return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, int> mpp;
        for (string w : words){
            mpp[w]++;
        }
        
        vector<string> ans;
        for (string w : words){
            vector<int> dp(w.length(), -1);
            if (helper(mpp, 0, w, 0, dp)) ans.push_back(w);
        }
        
        return ans;
    }
};