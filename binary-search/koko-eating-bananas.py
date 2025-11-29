class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def getTime(spd: int) -> int:
            total = 0
            for hrs in piles:
                if spd >= hrs:
                    total += 1
                else:
                    total += hrs // spd
                    if hrs % spd != 0:
                        total += 1
            return total
        
        left, right = 1, max(piles)
        while left < right:
            mid = (right + left) // 2
            if getTime(mid) <= h:
                right = mid
            else:
                left = mid + 1
            print("looped")
        return left
        
        