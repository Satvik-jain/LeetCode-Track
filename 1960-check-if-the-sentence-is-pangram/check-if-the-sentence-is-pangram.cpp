class Solution {
public:
    bool checkIfPangram(string s) {
        if(s.length() < 26) return false;
        unordered_map<char, int> mpp;
        for (auto c: s){
            mpp[c]++;
            if (mpp.size() == 26) return true;
        }
        return false;
    }
};