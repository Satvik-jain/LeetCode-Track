class Solution {
public:
    string helper(string s, int left, int right, int ans){
        if (left < 0 || right >= s.length()) return s.substr(left+1, right-left-1);
        if (s[left] != s[right]) return s.substr(left+1, right-left-1);
        if (s[left]==s[right]){
            ans++;
            left--;
            right++;
        }
        return helper(s, left, right, ans);
    }
    string longestPalindrome(string s) {

        string ans1 = "", ans2 = "", ans;
        for (int i = 0; i < s.length(); i++){
            ans1 = helper(s, i, i, 0);
            if (s[i] == s[i+1]) ans2 = helper(s, i, i+1, 0);
            else ans2 = "";
            ans1 = (ans1.length() > ans2.length()) ?ans1:ans2;
            ans = (ans1.length() > ans.length()) ?ans1:ans;
            cout << ans1 << endl;
        }
        return ans;
    }
};