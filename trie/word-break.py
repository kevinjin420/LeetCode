class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        self.visited = set()
        return self.dfs(s, 0, words)
        
    def dfs(self, s, index, words):
        if index in self.visited:
            return False
        self.visited.add(index)
        if index == len(s):
            return True
        for i in range(index, len(s)):
            prefix = s[index:i+1]
            if prefix in words:
                if self.dfs(s, i+1, words):
                    return True
        return False