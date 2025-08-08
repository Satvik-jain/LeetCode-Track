class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int  n = nums.size();
        vector<int> hash(n, 0);
        for (int  j = 0; j < k; j++){
            auto i = queries[j];
            hash[i[0]]+=i[2];
            if (i[1] + 1 < n){
                hash[i[1] + 1]-=i[2];
            }
        }

        int count = 0; int ans = 0;

        for (int i = 0; i < n; i++){
            count+=hash[i];
            if (nums[i]-count > 0) return false;
        }
        return true; 
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0;
        int q = queries.size();
        if (!check(nums, queries, q)) return -1;
        int right = q;
        int ans;
        while(right>=left){
            int mid = (left+right)/2;
            if (!check(nums, queries, mid)){
                left = mid+1;
            }
            else{
                right = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};