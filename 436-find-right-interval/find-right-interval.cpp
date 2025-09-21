class Solution {
public:
    bool static comp(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        for (int i = 0; i < intervals.size(); i++){
            v.push_back({intervals[i][0], intervals[i][1], i});
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans(v.size());
        for (auto p = 0; p < intervals.size(); p++){
            auto it = v[p];
            int i = 0, j = intervals.size()-1, k = it[1];
            // want just bigger first element that k
            int res = -1;
            while(i <= j){
                int mid = (i+j)/2;
                int compare = v[mid][0];
                if(k > compare){
                    i = mid+1;
                }
                else 
                {
                    j = mid-1; res = v[mid][2];
                }
            }
            ans[v[p][2]] = res;
        }
        return ans;
    }
};