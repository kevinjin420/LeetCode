class Solution {
public:
    static bool s(const vector<int>& lhs, vector<int>& rhs){
        return (lhs[0]==rhs[0]) ? lhs[1]<rhs[1] : lhs[0]>rhs[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), s);
        int n = points.size(), res = 0;
        for(int i = 0; i < n-1; i++){
            int y = INT_MAX, y_i = points[i][1];
            for(int j = i + 1; j < n; j++){
                int y_j = points[j][1];
                if(y_j >= y_i && y > y_j){
                    res++;
                    y = y_j;
                }
            }
        }
        return res;
    }
};