class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> pre(n, 0);
        vector<int> suf(n, 0);

        int maxe1 = height[0];
        for (int i = 0; i < n; i++) {
            maxe1 = max(maxe1, height[i]);
            pre[i] = maxe1;
        }

        int maxe2 = height[n-1];
        for (int i = n-1; i >= 0; i--) {
            maxe2 = max(maxe2, height[i]);
            suf[i] = maxe2;
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            total += min(pre[i], suf[i]) - height[i];
        }

        return total;
    }
};
