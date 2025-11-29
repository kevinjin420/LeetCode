class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, curr, 0, target);
        return res;
    }

    void backtrack(vector<int>& candidates, vector<int>& curr, int index, int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) return;
            curr.push_back(candidates[i]);
            backtrack(candidates, curr, i + 1, target - candidates[i]);
            curr.pop_back();
        }
    }
};