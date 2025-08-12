class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> v(26, 0);
        for(auto i : s){ // O(n)
            v[i-'a']++;
        }

        vector<int> freq(n+1, 0);

        for (int i = 0; i < 26; i++){ // O(26)
            if (v[i]) freq[v[i]]++;
        }

        int ans = 0;

        for (int i = n-1; i>0; i--){
            if (freq[i] > 1) {
                if (i>0) {
                    ans+=(freq[i] - 1);
                    freq[i-1] += (freq[i] - 1);
                    freq[i] = 1;
                } 
                else{
                    ans += (freq[i] - 1);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};