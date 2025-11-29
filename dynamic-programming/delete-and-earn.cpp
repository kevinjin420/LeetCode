class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(*max_element(nums.begin(), nums.end()) + 1, 0);
        for(int n : nums) count[n]++;
        vector<int> memo(count.size(), 0);
        memo[1] = count[1];
        for(int i = 2; i < memo.size(); i++){
            memo[i] = max(memo[i-2] + i*count[i], memo[i-1]);
        }
        return memo[memo.size() - 1];
    }
};