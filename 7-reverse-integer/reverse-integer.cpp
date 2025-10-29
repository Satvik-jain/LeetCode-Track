class Solution {
public:
    int reverse(int x) {
        long long num = 0;
        int sign = 1;
        if (x < 0) sign = -1;
        if(x == INT_MIN) return 0;
        x = abs(x);
        while(x){
            num = num*10 + (x%10);
            x = x/10;
            if (num > INT_MAX) return 0;
        }
        return num*sign;
    }
};