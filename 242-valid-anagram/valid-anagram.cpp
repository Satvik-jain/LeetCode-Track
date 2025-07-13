class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26, 0), b(26, 0);
        for (int i = 0; i < s.length(); i++){
            a[s[i]-'a']++;
        }
        for (int j = 0; j < t.length(); j++){
            b[t[j]-'a']++;
        }
        return (a == b);
    }
};