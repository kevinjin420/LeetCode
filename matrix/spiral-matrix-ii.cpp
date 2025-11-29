class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        vector<vector<int>> res(m, vector<int>(n, INT_MIN));
        int r = 0;
        int c = 0;
        int dr = 0;
        int dc = 1;
        for(int i = 0; i < m * n; i++){
        res[r][c] = i+1;
        int newR = r + dr;
        int newC = c + dc;
        if(newR < 0 || newR >= m || newC < 0 || newC >= n || res[newR][newC] != INT_MIN){
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