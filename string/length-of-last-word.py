class Solution(object):
    def lengthOfLastWord(self, s):
        counter = 0
        length = 0
        foundword = False
        for i in range(len(s)):
            if s[len(s)-1-i] == " ":
                counter = 0
            else:
                counter += 1
                length += 1
                foundword = True
            if foundword == True and counter == 0:
                return length
        return length

        """
        :type s: str
        :rtype: int
        """
        