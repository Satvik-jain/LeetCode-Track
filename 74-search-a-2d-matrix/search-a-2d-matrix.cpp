class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++){
            if(matrix[i][m-1] >= target){
                if (binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
                else return false;
            }
        }
        return false;
    }
};