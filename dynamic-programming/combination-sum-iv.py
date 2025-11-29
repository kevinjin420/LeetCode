class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        self.cache = {}
        return self.dfs(nums, target)
    def dfs(self, nums, target):
        if target < 0:
            return 0
        if target == 0:
            return 1
        if target in self.cache:
            return self.cache[target]
        res = 0
        for num in nums:
            res += self.dfs(nums, target - num)
        self.cache[target] = res
        return res
        