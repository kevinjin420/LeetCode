class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int res = 0, idx = -1;
        for(int i = 0; i < dimensions.size(); i++){
            int diag = (dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]);
            if(diag > res){
                res = diag;
                idx = i;
            }
            else if(diag == res && (dimensions[idx][0] * dimensions[idx][1] < dimensions[i][0] * dimensions[i][1])){
                res = diag;
                idx = i;
            }
        }
        return dimensions[idx][0] * dimensions[idx][1];
    }
};