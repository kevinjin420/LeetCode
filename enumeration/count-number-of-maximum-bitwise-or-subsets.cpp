class Solution {
public:
    int maxOR;
    int countMaxOrSubsets(vector<int>& nums) {
        maxOR = 0;
        for (int num : nums) maxOR |= num;
        return backtrack(nums, 0, 0);
    }

private:
    int backtrack(vector<int>& nums, int index, int currentOR) {
        if (index == nums.size()) return currentOR == maxOR ? 1 : 0;
        if (currentOR == maxOR) return 1 << (nums.size() - index);
        return backtrack(nums, index + 1, currentOR | nums[index]) + backtrack(nums, index + 1, currentOR);
    }
};