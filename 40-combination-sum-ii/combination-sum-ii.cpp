class Solution {
public:
        void helper(vector<int>& coins, int amount, vector<vector<int>> &ans, vector<int> v, int n, int index){
        if (amount == 0){
            ans.push_back(v);
            return;
        }
        if (index >= n){
            return;
        }

        int taken = 0, not_taken = 0;

        if (coins[index]<=amount){
            v.push_back(coins[index]);
            helper(coins, amount-coins[index], ans, v, n, index+1);
            v.pop_back();
        }

        while(index+1 < n && coins[index] == coins[index+1]) index++;
        
        helper(coins, amount, ans, v, n, index+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> ans;
        vector<int> v;
        sort(coins.begin(), coins.end());
        helper(coins, amount, ans, v, n, 0);
        return ans;
    }
};