class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        map<vector<int>, int> rows;
        for(int i = 0; i < grid.size(); i++){
            rows[grid[i]]++;
        }
        for(int i = 0; i < grid[0].size(); i++){
            vector<int> col;
            for(int j = 0; j < grid.size(); j++){
                col.push_back(grid[j][i]);
            }
            res += rows[col];
        }
        return res;
    }
};