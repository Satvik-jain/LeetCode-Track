class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(128, 0);  // Use ASCII size
        for (char c : s) {
            v[c]++;
        }

        int ans = 0;
        bool has_odd = false;
        for (int count : v) {
            if (count % 2 == 0) {
                ans += count;
            } else {
                has_odd = true;
                ans += count - 1;
            }
        }
        return has_odd ? ans + 1 : ans;
    }
};
