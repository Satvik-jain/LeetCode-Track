class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        vector<int> v(60, 0);
        for (int i = 0;i < n; i++){
            v[s[i] - 'A']++;
        }
        int ans = 0;
        bool has_odd = false;
        for (int i = 0; i < 60; i++){
            if (v[i]%2 == 0){
                ans+=v[i];
            }
            else{
                has_odd = true;
                ans = ans + v[i] - 1;
            }
        }
        return (has_odd)? ans+1 : ans;
    }
};