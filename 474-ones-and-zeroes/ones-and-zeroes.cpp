class Solution {
public:
    vector<int> count(string s){
        int ones = 0;
        for(int i : s){
            if (i == '1') ones++;
        }
        int zeros = s.length() - ones;
        return {zeros, ones};
    }
    int helper(vector<string>& strs, int zero, int one, int index, vector<vector<vector<int>>>& dp){
        if (zero == 0 && one == 0) return 0;
        if (index == strs.size()) return 0;
        if (dp[index][zero][one] != -1) return dp[index][zero][one];
        auto temp = count(strs[index]);
        int z = temp[0], o = temp[1];
        int inc_ways, exc_ways;
        if (zero >= z && one >= o){
            inc_ways = 1 + helper(strs, zero-z, one-o, index+1, dp);
        }
        exc_ways = helper(strs, zero, one, index+1, dp);
        int ans = max(exc_ways, inc_ways);
        return dp[index][zero][one] = ans;
    }
    int findMaxForm(vector<string>& strs, int mz, int no) {
        vector<vector<vector<int>>> dp(601, vector<vector<int>>(mz+1, vector<int>(no+1, -1)));
        return helper(strs, mz, no, 0, dp);
    }
};