class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        int n = s.length();
        int m = t.length();
        if (n != m) return false;
        for (int i = 0; i < n; i++){
            a[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++){
            b[t[i] - 'a']++;
        }
        return (a == b);
    }
};