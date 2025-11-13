class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int cnt = 0;
        int ans = 0;
        int ones = 0;
        for (int i = n-1; i >= 0; i--){
            if (s[i] == '1'){
                ones++;
            }
            else if ((i+1 < n && s[i+1] != '0') || (i == n-1 && s[i] == '0')){
                ans+=ones*cnt;
                ones = 0;
                cnt++;
            }
            // cout << s[i] << ": " << ones << " " << cnt << " " << ans << endl;
        }
        if (s[0] == '1'){
            ans+=ones*cnt;
        }
        return ans;
    }
};