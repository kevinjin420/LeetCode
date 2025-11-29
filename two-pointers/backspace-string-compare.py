class Solution(object):
    def backspaceCompare(self, s, t):
        
        s_ans = []
        t_ans = []

        for char in s:
            if char != "#":
                s_ans.append(char)
            else:
                if s_ans != []:
                    s_ans.pop()

        for char in t:
            if char != "#":
                t_ans.append(char)
            else:
                if t_ans != []:
                    t_ans.pop()

        return s_ans == t_ans

        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        