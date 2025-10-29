class Solution {
public:
    string convert(string s, int n) {
        int N = s.length();
        if (n == 1 || n >= N) return s;
        vector<string> hash(n);
        int idx = 0;
        int curr = 1;
        for(int i = 0; i <N; i++){
            hash[idx]+=s[i];
            if (idx == 0) curr = 1;
            if (idx == n-1) curr = -1;
            idx+=curr;
        }
        string ans;
        for (int i = 0; i < n; i++){
            ans+=hash[i];
        }
        return ans;
    }
};