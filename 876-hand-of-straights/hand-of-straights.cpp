class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int n) {
        map<int, int> mpp;
        if (hand.size()%n != 0) return 0;
        for (int i : hand) mpp[i]++;
        while(mpp.size()){
            int prev = -1;
            int cnt = 0;
            for (auto &i: mpp){
                // cout << prev << " " << cnt << endl;
                if (cnt == n) break;
                if (prev!=-1 && i.first != prev+1){
                    return 0;
                }
                mpp[i.first]--;
                prev = i.first;
                if (mpp[i.first] == 0){
                    mpp.erase(i.first);
                }
                cnt++;
            }
            if (cnt!=n) return 0;
        }
        return true;
    }
};