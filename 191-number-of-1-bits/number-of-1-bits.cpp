class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n){
            if (n%2!=0) ans++;
            n/=2;
        }
        return ans;
    }
};