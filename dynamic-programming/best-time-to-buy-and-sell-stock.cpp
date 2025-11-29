class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p = -1;
        int min_p = INT_MAX;
        int res = 0;
        for(int p : prices){
            if(p < min_p){
                min_p = p;
                max_p = 0;
            }
            if(p > max_p && p > min_p){
                max_p = p;
            }
            res = max(res, max_p - min_p);
        }
        return res;
    }
};