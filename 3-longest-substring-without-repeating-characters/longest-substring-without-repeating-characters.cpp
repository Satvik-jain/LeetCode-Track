class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        unordered_map<int, int> mpp;
        int ans = INT_MIN;
        while(j < n){
            if (mpp.find(s[j]) == mpp.end()){
                ans = max(ans, j-i+1);
            }
            else{
                while(i < mpp[s[j]]+1){
                    mpp.erase(s[i]);
                    i++;
                }
            }
            mpp[s[j]] = j; j++;
        }
        return (ans!=INT_MIN) ? ans : 0;
    }
};