class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_so_far = 0;
        int ans = INT_MIN;
        for (int i = 0; i < values.size(); i++){
            ans = max(max_so_far + values[i] - i, ans);
            max_so_far = max(max_so_far, values[i] + i);
        }
        return ans;
    }
};