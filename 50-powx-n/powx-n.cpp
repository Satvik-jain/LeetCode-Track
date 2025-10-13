class Solution {
public:
double ow(double x, int n) {
        // cout << n;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n%2==0){
            double temp = ow(x, n/2);
            return temp*temp;
        }
        else{
            double temp = ow(x, n/2);
            return x*temp*temp;
        }
        return 1;
    }
    double myPow(double x, int n) {
        double ans = ow(x, n);
        if (n < 0){
            ans = 1/ans;
            cout << ans;
        }
        return ans;
    }
};