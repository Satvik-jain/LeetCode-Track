class Solution {
public:
    void sieve(vector<int>& spf){
        for (int i = 2; i<=1000; i++){
            if (spf[i]) continue;
            for (int j = i; j <= 1000; j=j+i){
                if (!spf[j]){
                    spf[j] = i;
                }
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> spf(1001, 0);
        sieve(spf); // NloglogN
        unordered_set<int> distinct;
        for (int i : nums){
            int n = i;
            while(n > 1){
                int p = spf[n];
                distinct.insert(p);
                while(n % p == 0){
                    n = n/p;
                }
            }
        }
        return distinct.size();
    }
};