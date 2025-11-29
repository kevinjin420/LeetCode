class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0, total = 0, res = 0;
        for(int right = 0; right < fruits.size(); right++){
            total += fruits[right][1];
            while(left <= right && min(
                fruits[right][0] - fruits[left][0] + abs(startPos - fruits[left][0]), 
                fruits[right][0] - fruits[left][0] + abs(startPos - fruits[right][0])
            ) > k){
                total -= fruits[left++][1];
            }
            res = max(res, total);
        }
        return res;
    }
};