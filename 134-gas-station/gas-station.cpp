class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;

        int sum = 0; int n = cost.size(); int index = 0;

        for (int i = 0; i < cost.size(); i++){
            gas[i] = gas[i] - cost[i];
            sum += gas[i];
            if (sum<0){
                sum = 0;
                index = (n+i+1)%n;
            }
        }
        return index;
    }
};