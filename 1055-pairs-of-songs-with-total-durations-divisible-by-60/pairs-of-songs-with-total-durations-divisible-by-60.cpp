class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // for (int i = 0; i < time.size(); i++){
            
        // }
        unordered_map<int, int> mpp;
        int ans = 0;
        for (int i = 0; i < time.size(); i++){
            int rem = time[i]%60;
            if (mpp.find(60-rem) != mpp.end()){
                ans = ans + mpp[60-rem];
            }
            mpp[rem]++;
        }
        if(mpp[0] >= 2){
            ans = ans + (double)((double)mpp[0]/2) * (mpp[0] - 1);
        }
        return ans;
    }
};