class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, 1);
        for (int  i = 0; i < n-1; i++){
            if (a[i] < a[i+1]){
                ans[i+1] = ans[i] + 1;
            }
        }
        for (int i = n-1; i>=1; i--){
            if (a[i-1] > a[i]){
                ans[i-1] = max(ans[i-1], ans[i] + 1);
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};