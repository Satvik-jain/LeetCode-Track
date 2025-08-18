class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int i = 0, j = 0;

        // max-heap {value, index}
        priority_queue<pair<int,int>> pq;

        while (j < n) {
            // add current element
            pq.push({nums[j], j});

            // if window size < k, just expand
            if (j - i + 1 < k) {
                j++;
                continue;
            }

            // remove stale elements (whose index < i)
            while (!pq.empty() && pq.top().second < i) {
                pq.pop();
            }

            // top is max of current window
            ans.push_back(pq.top().first);

            // slide the window forward
            i++;
            j++;
        }

        return ans;
    }
};
