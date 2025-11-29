class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0;
        for(int f : fruits){
            bool placed = false;
            for(int i = 0; i < baskets.size(); i++){
                if(f <= baskets[i]){
                    baskets[i] = 0;
                    placed = true;
                    break;
                }
            }
            if(!placed) res++;
        }
        return res;
    }
};