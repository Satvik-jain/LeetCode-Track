class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;
        vector<vector<char>> hash(n);
        int idx = 0;
        bool down = true;
        for(int i = 0; i < s.length(); i++){
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
            for (int j = 0; j < hash[i].size(); j++){
                ans.push_back(hash[i][j]);
            }
        }
        return ans;
    }
};