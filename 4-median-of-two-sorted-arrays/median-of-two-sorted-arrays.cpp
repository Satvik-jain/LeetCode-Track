class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> max_q;
        priority_queue<int, vector<int>, greater<int>> min_q;
        int i = 0, j = 0;
        int ok = 0;
        while(i<nums1.size() && j<nums2.size()){
            if (!ok){
                max_q.push(nums1[i]);
                min_q.push(nums2[j]);
            }
            else{
                min_q.push(nums1[i]);
                max_q.push(nums2[j]);
            }
            ok=!ok;
            i++; j++;
        }
        while(i<nums1.size()){
            if (!ok){
                max_q.push(nums1[i]);
            }
            else{
                min_q.push(nums1[i]);
            }
            ok=!ok;
            i++;
        }
        while(j<nums2.size()){
            if (!ok){
                max_q.push(nums2[j]);
            }
            else{
                min_q.push(nums2[j]);
            }
            ok=!ok;
            j++;
        }
        while(max_q.size() > min_q.size() + 1 || min_q.size() > max_q.size() + 1){
            if (min_q.size() > max_q.size()){
                int temp = min_q.top();
                min_q.pop();
                max_q.push(temp);
            }
            else{
                int temp = max_q.top();
                max_q.pop();
                min_q.push(temp);
            }
        }
        // cout << min_q.top() << max_q.top();
        while(!min_q.empty() && !max_q.empty() && max_q.top() > min_q.top()){
            int e1 = max_q.top(); max_q.pop();
            int e2 = min_q.top(); min_q.pop();
            min_q.push(e1);
            max_q.push(e2);
        }
        if (min_q.size() == max_q.size()) return (min_q.top() + max_q.top())/2.0;
        else return (min_q.size() > max_q.size())?min_q.top():max_q.top();
    }
};