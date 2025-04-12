class Solution {
public:
int helper(int sum,  vector<int> &coins, int n, vector<vector<int>>&t){
        if (n<0) return INT_MAX-1;
        if (sum == 0){
            return 0;
        }
        if(t[n][sum] != INT_MAX) return t[n][sum];     
        
        // vector<int> op1 = v;
        // vector<int> op2 = v;
    
        int a = coins[n];
        if (a > sum){
            return t[n][sum] = helper(sum, coins, n-1 ,t);
        }
        // op1.push_back(a);
        return t[n][sum] = min(helper(sum-a, coins, n, t)+1, helper(sum, coins, n-1, t));
    }
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();

        if (n==1 && coins[0] == 1) return sum;
        sort(coins.begin(), coins.end());
        vector<vector<int>> t(n, vector<int>(sum+1, INT_MAX));
        
        vector<int> v;
        // v.push_back()
        int res = helper(sum, coins, n-1, t);
        return  (res == INT_MAX-1) ? -1 : res;
    }
};