class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int totalMax = nums[0];
        int totalMin = nums[0];
        for(int i = 1; i < nums.size(); i++){
            totalMax = max(totalMax, nums[i]);
            totalMin = min(totalMin, nums[i]);
        }
        int res = totalMax - totalMin - (k * 2);
        return max(res, 0);
    }
};