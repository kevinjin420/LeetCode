class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = 0;
        while(row < matrix.size()){
            if(matrix[row][0] <= target && matrix[row][matrix[0].size() - 1] >= target) break;
            row++;
        }
        if(row >= matrix.size()) return false;
        for(int n : matrix[row]) if(n == target) return true;
        return false;
    }
};