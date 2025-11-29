class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool vert0 = false;
        bool horiz0 = false;
        if(matrix[0][0] == 0){
            vert0 = true;
            horiz0 = true;
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(i == 0) horiz0 = true;
                    if(j == 0) vert0 = true;
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if(vert0) for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        if(horiz0) for(int i = 1; i < matrix[0].size(); i++) matrix[0][i] = 0;
    }
};