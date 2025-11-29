class Solution(object):
    def longestCommonPrefix(self, strs):
        strs.sort()
        ans = ""
        found = True
        for i in range (len(strs[0])):
            for j in range (len(strs)):
                if strs[0][i] != strs[j][i]:
                    found = False
            if found == False:
                return ans
            ans += strs[0][i]
        return ans

        """
        :type strs: List[str]
        :rtype: str
        """
        