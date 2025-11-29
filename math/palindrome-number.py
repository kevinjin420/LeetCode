class Solution(object):
    def isPalindrome(self, x):
        if x < 0:
            return False

        reversed = 0
        temp = x

        while temp != 0:
            reversed = reversed * 10 + temp % 10
            temp //= 10

        return reversed == x
        """
        :type x: int
        :rtype: bool
        """
        