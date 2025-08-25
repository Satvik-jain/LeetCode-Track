class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int w = n-k;
        int i = 0, j = 0;
        int ans = INT_MAX, sum = 0;
        while(j < n){
            sum = sum + arr[j];
            if (j-i+1 < w){
                j++;
                continue;
            }
            else if (j-i+1 > w){
                sum = sum - arr[i];
                i++;
            }
            ans = min(ans, sum);
            cout << i << " " << j << " " << ans << endl;
            j++;
        }
        return accumulate(arr.begin(), arr.end(), 0) - ans;
    }
};