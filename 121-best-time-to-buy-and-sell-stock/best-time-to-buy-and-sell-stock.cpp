class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mine = INT_MAX;
        int profit = 0;
        for (int i: prices){
            if (i < mine) mine = i;
            profit = max(profit, i - mine);
        }
        return profit;
    }
};