class Solution(object):
    def plusOne(self, digits):
        number = 0
        for i in range(len(digits)):
            number = number * 10 + digits[i]
        number += 1
        for j in range(len(str(number)) - len(digits)):
            digits.append(0)
        for k in range(len(digits)):
            digits[len(digits)-1-k] = number % 10
            number //= 10
        return digits
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        