class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n!=m) return false;
        unordered_map<char, char> mpp;
        for (int i = 0; i < n; i++){
            if (mpp.find(s[i]) == mpp.end()){
                mpp[s[i]] = t[i];
            }
            else{
                if (mpp[s[i]]!=t[i]) return false;
            }
        }
        mpp.clear();
        for (int i = 0; i < n; i++){
            if (mpp.find(t[i]) == mpp.end()){
                mpp[t[i]] = s[i];
            }
            else{
                if (mpp[t[i]]!=s[i]) return false;
            }
        }
        return true;
    }
};