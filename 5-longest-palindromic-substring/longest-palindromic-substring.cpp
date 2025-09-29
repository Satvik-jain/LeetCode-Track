class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int len = 1;
        int start=0, end=0;
        for (int i = 0; i < n; i++){
            int prev = i-1, next = i+1;
            while(prev >= 0 && next < n && s[next] == s[prev]){
                if (next-prev+1 > len){
                    len = next-prev+1;
                    start = prev;
                    end = next;
                }
                prev--;
                next++;
            }

            prev = i, next = i+1;
            while (prev >= 0 && next < n && s[prev] == s[next]) {
                if (next - prev + 1 > len) {
                    len = next - prev + 1;
                    start = prev;
                    end = next;
                }
                prev--;
                next++;
            }
        }
        string ans = s.substr(start, end - start + 1);
        return ans;
    }
};