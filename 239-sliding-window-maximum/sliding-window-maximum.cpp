class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        // int max = INT_MIN;
        unordered_map<int, int> mpp;
        priority_queue<int> q;
        vector<int> ans;
        while(j < n){
            mpp[nums[j]]++;
            if (j - i + 1 < k){
                q.push(nums[j]);
                j++;
            }
            else if (j - i + 1 == k){
                q.push(nums[j]);
                
                while (!q.empty() && mpp[q.top()] == 0) q.pop();
                ans.push_back(q.top());
                mpp[nums[i]]--;
                i++; j++;
            }
        }
        return ans;
    }
};