class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> res;
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        int r = 0;
        int c = 0;
        int dr = 0;
        int dc = 1;
        for(int i = 0; i < numRows * numCols; i++){
            res.push_back(matrix[r][c]);
            matrix[r][c] = INT_MIN;
            int newR = r + dr;
            int newC = c + dc;
            if(newR < 0 || newR >= numRows || newC < 0 || newC >= numCols || matrix[newR][newC] == INT_MIN){
                int temp = dc;
                dc = -dr;
                dr = temp;
            }
            r += dr;
            c += dc;
        }
        return res;
    }
};