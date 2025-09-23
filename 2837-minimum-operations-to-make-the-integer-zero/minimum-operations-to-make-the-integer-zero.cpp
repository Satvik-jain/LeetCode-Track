class Solution {
public:


    int makeTheIntegerZero(long long x, int y) {
        using ll = long long;;
        ll m = x;
        for (int i = 1; i <= 60; i++){
            x = m-(i)*(ll)y;
            if (x < 0) continue; // why
            if (x < i) continue; // why
            if (__builtin_popcountll(x) <= i) return i; 
        }
        return -1;
    }
};