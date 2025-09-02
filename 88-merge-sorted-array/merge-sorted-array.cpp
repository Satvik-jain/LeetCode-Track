class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, index = m+n-1;
        // if (m == 0){
        //     nums1 = nums2;
        //     return;
        // }
        // if (n == 0) return;
        while(i >= 0 && j >= 0){
            if (nums2[j] > nums1[i]){
                nums1[index] = nums2[j]; 
                j--;
                index--;
            }
            else if (nums2[j] < nums1[i]){
                nums1[index] = nums1[i]; 
                i--;
                index--;
            }
            else{
                nums1[index] = nums1[i];
                index--;
                nums1[index] = nums1[i];
                index--; i--; j--;
            }
        }
        while (j!=-1){
            nums1[index] = nums2[j];
            index--; j--;
        }
        while (i!=-1){
            nums1[index] = nums1[i];
            index--; i--;
        }
    }
};