class Solution {
public:
    int fib(int n) {
        // bottom up approach
        if(n==0) return 0;
        int prev = 1;
        int prev2 = 0;
        for (int i = 2; i < n+1; i++){
            int curr = prev  + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};