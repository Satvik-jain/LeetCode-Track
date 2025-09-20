class Solution {
public:
    bool helper(unordered_set<string> &dict, int index, string &word, int k, vector<int> &dp) {
        if (index == word.length()) return (k > 1);
        if (dp[index] != -1) return dp[index];

        string new_w = "";
        for (int i = index; i < word.size(); i++) {
            new_w += word[i];
            if (dict.count(new_w)) { // ✅ check existence in set
                if (helper(dict, i + 1, word, k + 1, dp))
                    return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        unordered_set<string> dict;
        for (string &w : words) dict.insert(w); // ✅ store words in set

        vector<string> ans;
        for (string &w : words) {
            vector<int> dp(w.length(), -1);
            if (helper(dict, 0, w, 0, dp))
                ans.push_back(w);
        }
        return ans;
    }
};
