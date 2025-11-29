class Solution {
public:
    vector<vector<int>> res;
    vector<int> copy;
    vector<vector<int>> subsets(vector<int>& nums) {
        copy = nums;
        vector<int> curr;
        backtrack(0, curr);
        return res;
    }
    
    void backtrack(int index, vector<int>& curr){
        if(index == copy.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(copy[index]);
        backtrack(index + 1, curr);
        curr.pop_back();
        backtrack(index + 1, curr);
    }

};