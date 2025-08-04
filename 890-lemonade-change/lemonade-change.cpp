class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size(); int five = 0; int ten = 0; int num;
        for (int i = 0; i < n; i++){
            num = bills[i];
            // cout << num << endl;
            if (num == 5) five++;
            else if (num == 10){
                ten++;
                if (five >= 1){
                    five--;
                }
                else return false;
            }
            else{
                if (five >= 1 && ten >= 1){
                    ten--; five--;
                }
                else if (five >= 3){
                    five = five - 3;
                }
                else return false;
            }
        }
        return true;
    }
};