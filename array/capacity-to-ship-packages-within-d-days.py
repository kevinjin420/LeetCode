class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        def getTime(spd: int) -> int:
            count = 0
            cur = 0
            for w in weights:
                if w > spd or cur + w > spd:
                    count += 1
                    cur = w
                else:
                    cur += w
            if cur != 0:
                count += 1
            return count
        left, right = max(weights), sum(weights)
        while left < right:
            mid = (right + left) // 2
            if getTime(mid) <= D:
                right = mid
            else:
                left = mid + 1
        return left