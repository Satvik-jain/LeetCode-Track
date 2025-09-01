class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mpp;
        int i = 0, n = s.length(), j = 0;
        int maxe = 0;
        while(j < n){
            if(mpp.find(s[j])!=mpp.end()){
                while(s[i]!=s[j]){
                    mpp.erase(s[i]);
                    i++;
                }
                mpp.erase(s[i]);
                i++;
            }
            maxe = max(j-i+1, maxe);
            // cout << s[j] << " " << maxe << endl;
            mpp[s[j]]++;
            j++;
        }
        return maxe;
    }
};