class Solution(object):
    def removeDuplicates(self, nums):
        duplicates = 0
        ans = []
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                duplicates += 1
            else:
                ans.append(nums[i])
        ans.append(nums[len(nums)-1])
        unique = len(nums) - duplicates
        for j in range (unique):
            nums[j] = ans[j]
        for k in range (unique+1,len(nums)):
            nums[k] = "_"
        return unique
            
        """
        :type nums: List[int]
        :rtype: int
        """
        