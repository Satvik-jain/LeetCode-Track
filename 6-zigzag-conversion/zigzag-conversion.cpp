class Solution {
public:
    string convert(string s, int n) {
        int N = s.length();
        if (n == 1 || n >= N) return s;
        vector<string> hash(n);
        int idx = 0;
        bool down = true;
        for(int i = 0; i <N; i++){
            hash[idx].push_back(s[i]);
            if (idx < n-1 && down) idx++;
            else{
                down = false;
                idx--;
                if (idx==-1){
                    idx = 1;
                    down = true;
                }
            }

        }
        string ans;
        for (int i = 0; i < n; i++){
            ans+=hash[i];
        }
        return ans;
    }
};