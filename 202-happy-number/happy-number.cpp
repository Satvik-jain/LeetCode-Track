class Solution {
public:
    int ss(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(true){
            if (st.count(n)) return false;
            st.insert(n);
            n = ss(n);
            if (n==1) return true;
        }
        return false;
    }
};