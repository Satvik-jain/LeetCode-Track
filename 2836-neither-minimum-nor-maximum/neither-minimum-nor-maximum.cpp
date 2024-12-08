class Solution {
public:
    int findNonMinOrMax(vector<int>& v) {
        for(int j : v){
            if (j!=*max_element(v.begin(), v.end()) && j !=*min_element(v.begin(), v.end())){
                return j;
            }
        }
        return -1;
    }
};