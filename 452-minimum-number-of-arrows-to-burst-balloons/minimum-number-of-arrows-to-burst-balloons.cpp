class Solution {
public:
    bool static comp(vector<int>& v1, vector<int>& v2){
        return (v1[0] == v2[0]) ? (v1[1] < v2[1]) : (v1[0] < v2[0]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int arrow = 1;
        int compare = points[0][1];
        int ul = points[0][1];
        for(auto it : points){
            if (it[0] <= compare && it[0] <= ul){
                ul = min(ul, it[1]);
                cout << ul << endl;
                continue;
            }
            compare = it[1]; 
            ul = compare;
            arrow++;
        }
        return arrow;
    }
};