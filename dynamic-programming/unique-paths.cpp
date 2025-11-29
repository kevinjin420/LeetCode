class Solution {
public:
    int uniquePaths(int m, int n) {
        static vector<vector<int>> memo(101, vector<int>(101, 0));
        if(m == 1 || n == 1) return 1;
        if(!memo[m][n]) memo[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        return memo[m][n];
    }
};