class Solution {
public:
    static bool sorter(vector<int> &v1, vector<int>& v2){
        if (v1[1]!=v2[1]){
            return v1[1]<v2[1];
        }
        return v1[0]<v2[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), sorter);

        auto temp = intervals[0];
        int meet = 1;

        for (int i = 1; i< n;i++){
            if (temp[1] <= intervals[i][0]){
                meet++;
                temp = intervals[i];
            }
        }

        return n - meet;
    }
};