class Solution(object):
    def romanToInt(self, s):
        code = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        solution = 0
        s = s.replace("IV","IIII").replace("IX","VIIII").replace("XL","XXXX").replace("XC","LXXXX").replace("CD","CCCC").replace("CM","DCCCC")

        for i in range(len(s)):
            solution += code[s[i]]

        return solution
        """
        :type s: str
        :rtype: int
        """
        