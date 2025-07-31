class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 0;
        while(i<n){
            if (!a[i]){
                i++; 
            }
            else{
                a[j] = a[i];
                j++; i++;
            }
        }
        while(j<n){
            a[j] = 0;
            j++;
        }
    }
};