class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        c = -1
        min_delta = float('inf')
        for i in range (len(nums)):
            left, right = i+1, len(nums) - 1
            while left < right:
                if nums[i] + nums[left] + nums[right] == target:
                    return target
                if abs(target - (nums[i] + nums[left] + nums[right])) < min_delta:
                    min_delta = abs(target - (nums[i] + nums[left] + nums[right]))
                    c = nums[i] + nums[left] + nums[right]
                if nums[i] + nums[left] + nums[right] < target:
                    left += 1
                else:
                    right -= 1
        return c
        