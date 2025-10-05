class Solution {
public:
    bool is_valid(int mid, vector<int>& piles, int h){
        int pre = 0;
        for (int i : piles){
            pre = pre + i/mid;
            if (i%mid!=0) pre+=1;
            if (pre > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        int res = 0;
        while(i <= j){
            int mid = (i+j)/2;
            if (is_valid(mid, piles, h)){
                res = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return res;
    }
};