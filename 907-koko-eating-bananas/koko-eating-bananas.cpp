class Solution {
public:
    int is_valid(int mid, vector<int>& piles, int h){
        int hrs = 0;
        for (int i = 0; i < piles.size(); i++){
            if (piles[i]%mid==0) hrs += piles[i]/mid;
            else hrs += 1 + piles[i]/mid;
            if (hrs > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxe = *max_element(piles.begin(), piles.end());
        int n = piles.size();
        if (n == h) return maxe;
        int i = 1, j = maxe;
        int ans = 0;
        while(i <= j){
            int mid = (i+j)/2;
            if (is_valid(mid, piles, h)){
                ans = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return ans;
    }
};