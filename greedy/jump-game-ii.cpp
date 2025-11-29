class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), numeric_limits<int>::max() / 2);
        memo[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= min(nums[i], (int)nums.size() - 1 - i); j++){
                memo[i+j] = min(memo[i+j], memo[i] + 1);
            }
        }
        return memo[memo.size() - 1];
    }
};