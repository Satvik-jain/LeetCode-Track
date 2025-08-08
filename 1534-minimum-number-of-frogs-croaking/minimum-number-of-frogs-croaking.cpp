class Solution {
public:
    bool check(unordered_map<char, int> mpp){
        if (mpp['c'] >= mpp['r'] && mpp['r'] >= mpp['o'] && mpp['o'] >= mpp['a'] && mpp['a'] >= mpp['k']) return true;
        else return false;
    }
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> mpp;
        mpp['c'] = 0;mpp['r'] = 0;mpp['o'] = 0;mpp['a'] = 0;mpp['k'] = 0;
        int n = croakOfFrogs.size();
        int frogs = 0;
        for (auto i : croakOfFrogs){
            mpp[i]++;
            frogs = max(frogs, mpp[i]);
            if(!check(mpp)) return -1;
            if (i == 'k'){
                for (auto c: mpp){
                    mpp[c.first]--;
                }
            }
        }
        for (auto c: mpp){
            if (mpp[c.first] != 0) return -1;
        }
        return frogs;
    }
};