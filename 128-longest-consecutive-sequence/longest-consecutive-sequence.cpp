class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        unordered_set<int> s;
        for (int i : nums) s.insert(i);
        int ans = INT_MIN;
        int series = 1;
        for (int i : s){
            if (s.count(i-1)) continue;
            int k = i+1;
            while(s.count(k)){
                series++;
                cout << series << " " << k << endl;
                k++;
            }
            ans = max(ans, series);
            series = 1;
        }
        return ans;
    }
};