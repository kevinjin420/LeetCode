class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int curMin = nums[0];
        int maxRes = 0;
        for(int n : nums){
            maxRes = max(maxRes, n - curMin);
            curMin = min(curMin, n);
        }
        return maxRes == 0 ? -1 : maxRes;
    }
};