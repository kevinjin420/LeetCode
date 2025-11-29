class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size();){
            vector<int> curr;
            int start = i;
            for(; i < start + 3; i++) curr.push_back(nums[i]);
            if(curr[1] - curr[0] > k || curr[2] - curr[1] > k || curr[2] - curr[0] > k) return {};
            res.push_back(curr);
        }
        return res;
    }
};