class Solution {
public:
    void helper(vector<int>& coins, int amount, vector<vector<int>> &ans, vector<int> v, int n, int index){
        if (amount == 0){
            ans.push_back(v); return;
        }
        if (index >= n){
            return;
        }

        int taken = 0, not_taken = 0;

        if (coins[index]<=amount){
            v.push_back(coins[index]);
            helper(coins, amount-coins[index], ans, v, n, index);
            v.pop_back();
        }
        helper(coins, amount, ans, v, n, index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        vector<vector<int>> ans;
        vector<int> v;
        helper(coins, amount, ans, v, n, 0);
        return ans;
    }
};