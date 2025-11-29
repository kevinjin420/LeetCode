class Solution(object):
    def isValid(self, s):
        stack = []
        for char in s:
            if char in "([{":
                stack.append(char)
            else:
                if stack == [] or (char == ")" and stack[-1] != "(") or (char == "]" and stack[-1] != "[") or (char == "}" and stack[-1] != "{"):
                    return False
                stack.pop()
        return stack == []
        """
        :type s: str
        :rtype: bool
        """
        