class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        vector<int> f = {1};
        res.push_back(f);
        for(int i = 2; i <= rowIndex + 1; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < i - 1; j++){
                row.push_back(res[i-2][j-1] + res[i-2][j]);
            }
            row.push_back(1);
            res.push_back(row);
        }

        return res[rowIndex];
    }
};