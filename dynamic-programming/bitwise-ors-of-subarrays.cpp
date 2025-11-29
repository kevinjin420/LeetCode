class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, curr;
        for(int i : arr){
            unordered_set<int> next;
            next.insert(i);
            for(int j : curr) next.insert(i | j);
            res.insert(next.begin(), next.end());
            curr = next;
        }
        return res.size();
    }
};