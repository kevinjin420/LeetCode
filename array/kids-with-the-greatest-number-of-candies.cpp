class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int max_candies = *std::max_element(candies.begin(), candies.end());
        for(int c : candies){
            if(c + extraCandies >= max_candies){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};