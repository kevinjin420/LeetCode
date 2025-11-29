class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++) res = max(res, abs(nums[i] - nums[i+1]));
        res = max(res, abs(nums.front() - nums.back()));
        return res;
    }
};