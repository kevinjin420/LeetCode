class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        cur = 0
        ans = 0
        first = {0:0}
        for i in range(0, len(nums)):
            cur += 1 if nums[i] == 1 else -1
            if cur in first:
                ans = max(ans, i+1-first[cur])
            else:
                first[cur] = i+1
        return ans