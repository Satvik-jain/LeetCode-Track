class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = n*m-1;
        while(i <= j){
            int mid = (i+j)/2;
            int r = mid/m;
            int c = mid%m;
            if (matrix[r][c] == target){
                return true;
            }
            if (matrix[r][c] < target){
                i = mid+1;
            }
            else j = mid - 1;
        }
        return false;
    }
};