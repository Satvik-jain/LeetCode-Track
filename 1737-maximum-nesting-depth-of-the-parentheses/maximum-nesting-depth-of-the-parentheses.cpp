class Solution {
public:
    int maxDepth(string s) {
        int num = 0;
        int maxe = INT_MIN;
        for (auto i: s){
            if ('(' == i){
                num++;
            }
            maxe = max(maxe, num);
            if (')' == i){
                num--;
            }
        }
        return maxe;
    }
};