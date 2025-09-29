class Solution {
public:
    int countSubstrings(string s) {
        int prev = 0, next = 0;
        int ans = s.length();
        for (int i = 0; i < s.length(); i++){
            prev = i-1, next = i+1;
            while(prev >= 0 && next < s.length() && s[prev] == s[next]){
                ans++;
                prev--;
                next++;
            }
            prev = i, next = i+1;
            while(prev >= 0 && next < s.length() && s[prev] == s[next]){
                ans++;
                prev--;
                next++;
            }
        }
        return ans;
    }
};