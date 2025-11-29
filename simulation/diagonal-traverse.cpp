class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        int row = 0, col = 0;
        vector<int> result(m * n);
        bool up = true;
        for(int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];
            if ((row + col) % 2 == 0) {
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else { row--; col++; }
            } else {
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else { row++; col--; }
            }
        }
        return result;
    }
};