class Solution {
public:
    int m;
    int n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        vector<vector<int>> memo(101, vector<int>(101, 0));
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        return getPaths(0, 0, obstacleGrid, memo);
    }

    int getPaths(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo){
        if(obstacleGrid[i][j] || i > m-1 || j > n-1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(memo[i][j]) return memo[i][j];
        if(i == m-1) return memo[i][j] = getPaths(i, j+1, obstacleGrid, memo);
        else if(j == n-1) return memo[i][j] = getPaths(i+1, j, obstacleGrid, memo);
        else return memo[i][j] = getPaths(i+1, j, obstacleGrid, memo) + getPaths(i, j+1, obstacleGrid, memo);
    }
};