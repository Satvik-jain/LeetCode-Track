class DetectSquares {
public:
    map<vector<int>, int> mpp;
    DetectSquares() {
        mpp.clear();
    }
    
    void add(vector<int> point) {
        mpp[point]++;
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        int x = point[0], y = point[1];
        for (auto& i: mpp){
            vector<int> pt = i.first;
            int x1 = pt[0], y1 = pt[1];
            if (x1 == x || y1 == y || abs(x1-x)!=abs(y1-y)) continue;
            vector<int> p1 = {x1, y};
            vector<int> p2 = {x, y1};
            if (mpp[p1] && mpp[p2]){
                cnt = cnt + (mpp[p1]*mpp[p2]*i.second);
            }
        }
        return cnt;
    }
};