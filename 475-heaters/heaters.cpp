class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = INT_MIN;
        int up=INT_MAX, lo=up;
        for(int h : houses){
            int i = 0, j = heaters.size()-1;
            while(i <= j){
                int mid = (i+j)/2;
                if (h == heaters[mid]){
                    lo = h;
                    break;
                }
                if (h < heaters[mid]){
                    j = mid-1;
                }
                else{
                    lo = heaters[mid];
                    i = mid+1;
                }
            }
            i = 0, j = heaters.size()-1;
            while(i <= j){
                int mid = (i+j)/2;
                if (h == heaters[mid]){
                    up = h;
                    break;
                }
                if (h < heaters[mid]){
                    j = mid-1;
                    up = heaters[mid];
                }
                else{
                    i = mid+1;
                }
            }
            cout << lo << " " << up << endl;
            res = max(res, min(abs(up-h), abs(h-lo))); 
        }
        return res;
    }
};