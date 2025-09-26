class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(), k = groupSize;
        
        if (n%k!=0) return false;

        sort(hand.begin(), hand.end());

        map<int, int> mpp;

        for (int i : hand) mpp[i]++;

        while(!mpp.empty()){
            auto curr = mpp.begin(); // smallest
            int val = curr->first; // value
            for(int i  = 0; i < k; i++){
                int curr = val+i;
                auto it = mpp.find(curr);
                if (it == mpp.end()) return false;

                if (--(it->second) == 0) {
                    mpp.erase(it);
                }

            }
        }
        return true;
    }
};