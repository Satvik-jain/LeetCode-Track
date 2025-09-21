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

    int helper(vector<pair<int,int>>& counts, int zero, int one, int index, vector<vector<vector<int>>>& dp){
        if (zero == 0 && one == 0) return 0;
        if (index == counts.size()) return 0;
        if (dp[index][zero][one] != -1) return dp[index][zero][one];

        int z = counts[index].first;
        int o = counts[index].second;

        int inc_ways = 0, exc_ways = 0;
        if (zero >= z && one >= o){
            inc_ways = 1 + helper(counts, zero-z, one-o, index+1, dp);
        }
        exc_ways = helper(counts, zero, one, index+1, dp);

        int ans = max(exc_ways, inc_ways);
        return dp[index][zero][one] = ans;
    }

    int findMaxForm(vector<string>& strs, int mz, int no) {
        vector<pair<int,int>> counts;
        for(auto &s : strs){
            auto temp = count(s);
            counts.push_back({temp[0], temp[1]});
        }

        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(mz+1, vector<int>(no+1, -1)));
        return helper(counts, mz, no, 0, dp);
    }
};
