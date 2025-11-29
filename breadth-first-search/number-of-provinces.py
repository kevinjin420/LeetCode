class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        count = 0
        visited = set()

        def searchProv(i):
            for j in range(len(isConnected[i])):
                if isConnected[i][j] == 1 and j not in visited:
                    visited.add(j)
                    searchProv(j)
                    
        for i in range(len(isConnected)):
            if i not in visited:
                visited.add(i)
                searchProv(i)
                count += 1
        return count
