class Solution {
public:
    int helper(int n, int r){
        if (r == 1) return n;
        if (r == 0) return 1;
        if (r < 0) return 0; 
        return (int)(((long double)(n - r + 1) / r) * helper(n, r - 1) + 0.5L);

    }
    int uniquePaths(int m, int n) {
        int p = max(m,n);
        int q = min(m,n);
        int r = q-1;
        n = p+q-2;
        return helper(n, r);
    }
};