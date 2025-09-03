class Solution {
public:
    int is_valid(vector<int>& w, int days, int mid){
        int day = 1;
        int cap = 0;
        for (int i = 0; i < w.size(); i++){
            cap+=w[i];
            if(cap > mid){
                cap = w[i];
                day++;
            }
            if (day > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int total_w = accumulate(w.begin(), w.end(), 0);
        int maxe = *max_element(w.begin(), w.end());
        int i = maxe, j = total_w;
        int res = -1;
        while(i <= j){
            int mid = (i+j)/2;
            if (is_valid(w, days, mid)){
                res = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return res;
    }
};