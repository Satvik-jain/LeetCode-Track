class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        
        using ll = long long;
        int n = b1.size();
        ll mine = INT_MAX;
    map<int, int> mpp;
        for (int i = 0; i < n; i++){
            mine = min(mine, (ll)min(b1[i], b2[i]));
            mpp[b1[i]]++;
            mpp[b2[i]]--;
        }

        vector<ll> transfer; int num; int freq; int rep;

        for (auto i : mpp){
            freq = i.second;
            num = i.first;
            if (freq%2!=0) return -1;
            rep = abs(freq/2);
            while(rep){
                transfer.push_back((ll)num);
                rep--;
            }
        }

        // sort(transfer.begin(), transfer.end());

        ll cost = 0;
        for (int i = 0; i < transfer.size()/2; i++){
            cost += min(mine*2, transfer[i]);
        }

        return cost;
    }
};