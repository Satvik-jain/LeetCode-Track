class Solution {
public:
    int fib(int n) {
        int i = 0; int j = 1;
        int temp = 0;
        for (int k = 0; k < n; k++){
            temp = i;
            i = j;
            j = temp + j;
        }
        return (n)? i:0;
    }
};