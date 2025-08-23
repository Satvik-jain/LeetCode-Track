class Solution {
public:
    double helper(double x, int n){
        if (n==1) return x;
        if (n==0) return 1;
        if (n%2 == 0){
            double k = helper(x, n/2);
            return k*k;
        }
        else{
            double k = helper(x, n/2);
            return k * k * x;
        }
    }
    double myPow(double x, int n) {
        double ans = helper(x, n);
        return (n >= 0) ? ans : 1/ans;
    }
};