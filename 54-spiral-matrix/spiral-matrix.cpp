class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int fr = 0, lr = m - 1, fc = 0, lc = n - 1;
        vector<int> v;

        while (fr <= lr && fc <= lc) {
            for (int i = fc; i <= lc; i++) {
                v.push_back(matrix[fr][i]);
            }
            fr++;

            if (fr <= lr) {
                for (int i = fr; i <= lr; i++) {
                    v.push_back(matrix[i][lc]);
                }
                lc--;
            }

            if (fc <= lc && fr <= lr) {
                for (int i = lc; i >= fc; i--) {
                    v.push_back(matrix[lr][i]);
                }
                lr--;
            }

            if (fr <= lr && fc <= lc) {
                for (int i = lr; i >= fr; i--) {
                    v.push_back(matrix[i][fc]);
                }
                fc++;
            }
        }

        return v;
    }
};
