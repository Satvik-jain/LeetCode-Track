class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int n = nums1.size();
        int cnt = 0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mpp[nums3[i] + nums4[j]]++;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int target = -1*(nums1[i] + nums2[j]);
                if (mpp.find(target) != mpp.end()){
                    cnt+=mpp[target];
                }
            }  
        }
        return cnt;
    }
};