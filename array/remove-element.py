class Solution(object):
    def removeElement(self, nums, val):
        count = 0
        ans = []
        for i in range(len(nums)):
            if nums[i] != val:
                ans.append(nums[i])
                count += 1
        for i in range (count):
            nums[i] = ans[i]
        return (count)
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        