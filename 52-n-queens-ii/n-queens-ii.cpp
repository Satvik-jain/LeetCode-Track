class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> queens(n); 
        solveNQueens(queens, 0, n, count);
        return count;
    }

private:
    void solveNQueens(vector<int>& queens, int row, int n, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(queens, row, col)) {
                queens[row] = col;
                solveNQueens(queens, row + 1, n, count);
            }
        }
    }

    bool isSafe(const vector<int>& queens, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (queens[i] == col || abs(queens[i] - col) == row - i) {
                return false;
            }
        }
        return true;
    }
};