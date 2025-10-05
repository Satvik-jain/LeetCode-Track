class Solution {
public:
    bool is_valid(int mid, vector<int>& piles, int h) {
        long long pre = 0;  // use long long to avoid overflow
        for (int i : piles) {
            pre += (i + mid - 1) / mid;  // ceil division
            if (pre > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        int res = j;  // worst case: eat at max pile size
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (is_valid(mid, piles, h)) {
                res = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return res;
    }
};

