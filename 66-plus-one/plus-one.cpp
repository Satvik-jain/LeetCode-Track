class Solution {
public:
    vector<int> plusOne(vector<int>&a) {
        int n = a.size();
        int carry = 1;
        int sum = 0;
        for (int i = n-1; i >= 0; i--){
            int sum = carry + a[i];
            int ones = sum%10;
            carry = sum/10;
            a[i] = ones;
        }
        if (carry){
            a.insert(a.begin(), carry);
        }
        return a;
    }
};