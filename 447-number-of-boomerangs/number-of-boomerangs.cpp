class Solution {
public:
    int dist(const vector<int>& v1, const vector<int>& v2) {
        int dx = v1[0] - v2[0];
        int dy = v1[1] - v2[1];
        return dx * dx + dy * dy;  // avoid pow for speed + precision
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> mpp;  // reset map for each i
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                mpp[dist(points[i], points[j])]++;
            }
            for (auto& it : mpp) {
                int t = it.second;
                if (t > 1) ans += t * (t - 1); 
            }
        }
        return ans;
    }
};
