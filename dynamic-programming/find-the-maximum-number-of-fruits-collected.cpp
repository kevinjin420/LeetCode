class Solution {
public:
    int n;
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        vector<vector<int>> reverse = fruits;
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) swap(reverse[i][j], reverse[j][i]);

        int diag = 0;
        for(int i = 0; i < n; i++) diag += fruits[i][i];

        return diag + getMax(fruits) + getMax(reverse);
    }

    int getMax(vector<vector<int>>& grid){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n - i - 1; j++){
                grid[i][j] = -1;
            }
        }

        for(int i = 1; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                // cout << "on " << i << " " << j << endl;
                if(j == n-1) grid[i][j] += max(grid[i-1][j-1], grid[i-1][j]);
                else grid[i][j] += max({grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
            }
        }
        return grid[n-2].back();
    }
};