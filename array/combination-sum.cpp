class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, curr, 0, 0, target);
        return res;
    }

    void backtrack(vector<int>& candidates, vector<int>& curr, int index, int sum, int target){
        if(sum == target){
            res.push_back(curr);
            return;
        }
        if(sum > target || index >= candidates.size()) return;
        curr.push_back(candidates[index]);
        backtrack(candidates, curr, index, sum + candidates[index], target);
        curr.pop_back();
        backtrack(candidates, curr, index + 1, sum, target);
    }
};