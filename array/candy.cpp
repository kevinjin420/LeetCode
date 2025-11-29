class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++) if(ratings[i] > ratings[i-1]) res[i] = res[i-1] + 1;
        int count = res.back();
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) res[i] = max(res[i+1] + 1, res[i]);
            count += res[i];
        }
        return count;
    }
};