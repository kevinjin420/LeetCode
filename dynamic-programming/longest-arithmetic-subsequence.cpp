class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 2;
        int n = nums.size();
        if(n <= 2) return n;
        vector<unordered_map<int, int>> memo(n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i]-nums[j];
                memo[i][diff] = (memo[j][diff] == 0) ? 2 : memo[j][diff] + 1;
                res = max(res, memo[i][diff]);
            }
        }
        return res;
    }
};