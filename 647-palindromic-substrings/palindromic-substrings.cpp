class Solution {
public:
    int helper(string s, int left, int right, int ans){
        if (left < 0 || right >= s.length() || s[left] != s[right]) return ans;
        if (s[left]==s[right]){
            ans++;
            left--;
            right++;
        }
        return helper(s, left, right, ans);
    }
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++){
            ans+=helper(s, i, i, 0) + helper(s, i, i+1, 0);
        }
        return ans;
    }
};