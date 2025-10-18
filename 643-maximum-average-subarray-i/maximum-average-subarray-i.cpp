class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0; int maxe = INT_MIN;
        while(j < n){
            if (j-i+1 > k){
                maxe = max((int)maxe, sum);
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            if (j-i+1 == k) maxe = max((int)maxe, sum);
            j++;
        }
        return (double)maxe/k;
    }
};