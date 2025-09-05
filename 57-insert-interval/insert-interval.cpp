class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0; int n = intervals.size();
        vector<vector<int>> ans;
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int start = newInterval[0], end = newInterval[1];
        while(i < n && newInterval[1] >= intervals[i][0]){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        // cout << start << " " << end;
        ans.push_back({start, end});
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};