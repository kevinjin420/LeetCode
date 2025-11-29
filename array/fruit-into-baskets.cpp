class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> curr;
        int left = 0, res = 0;
        for(int right = 0; right < fruits.size(); right++){
            curr[fruits[right]]++;
            while(curr.size() > 2){
                curr[fruits[left]]--;
                if(curr[fruits[left]] == 0) curr.erase(fruits[left]);
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};