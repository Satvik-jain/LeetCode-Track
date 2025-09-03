class Solution {
public:
    int is_valid(int mid, vector<int>& a, int m, int k){
        int set = 0, buq = 0;
        for (int i = 0; i < a.size(); i++){
            if (mid >= a[i]){
                set++;
            }
            else set = 0;
            if (set == k){
                set = 0;
                buq++;
            }
        } 
        return (buq>=m);
    }
    int minDays(vector<int>& a, int m, int k) {
        int n = a.size();
        // if (n < m*k) return -1;
        int maxe = *max_element(a.begin(), a.end());
        int mine = *min_element(a.begin(), a.end());
        int i = mine, j = maxe, res = -1;
        while(i <= j){
            int mid = (i+j)/2;

            if(is_valid(mid, a, m, k)){
                res = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return res;
    }
};