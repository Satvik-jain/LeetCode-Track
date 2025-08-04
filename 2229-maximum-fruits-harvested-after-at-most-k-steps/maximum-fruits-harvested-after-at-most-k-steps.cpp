class Solution {
public:
    int bs_up(vector<vector<int>>& arr, int i){ // i being dist of pos from startPos
        int s = 0;
        int e = arr.size();
        int mid = 0;
        int res = -1;
        while(e>s){
            mid = (s+e)/2;
            if (arr[mid][0] > i){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<vector<int>> left, right;
        for (int i = 0; i < n && fruits[i][0]<=startPos; i++){
            left.push_back({startPos - fruits[i][0], fruits[i][1]});
        }
        reverse(left.begin(), left.end());
        
        for (int i = 0; i < n; i++) {
            if (fruits[i][0] > startPos) right.push_back({fruits[i][0] - startPos, fruits[i][1]});
        }

        vector<int> left_pre(left.size()+1, 0), right_pre(right.size()+1, 0);

        for (int i = 0; i < left.size(); i++){
            left_pre[i+1] = left_pre[i] + left[i][1];
        }
        for (int i = 0; i < right.size(); i++){
            right_pre[i+1] = right_pre[i] + right[i][1];
        }

        int ans_max = 0;

        for (int i = 0; i <= k; i++){
            int index_left = bs_up(left, i);
            int index_right = (k - 2*i >= 0) ? bs_up(right, k-2*i) : 0;
            ans_max = max(ans_max, left_pre[index_left] + right_pre[index_right]);
        }
        for (int i = 0; i <= k; i++){
            int index_left = (k - 2*i >= 0) ? bs_up(left, k-2*i) : 0;
            int index_right = bs_up(right, i);
            ans_max = max(ans_max, left_pre[index_left] + right_pre[index_right]);
        }
        return ans_max;
    }
};