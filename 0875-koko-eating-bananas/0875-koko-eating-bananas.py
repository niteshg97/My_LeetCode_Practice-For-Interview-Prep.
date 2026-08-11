import math
from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        ans = r
        
        while l <= r:
            mid = (l + r) // 2
            hours = 0
            for p in piles:
                hours += math.ceil(p / mid)
            if hours <= h: 
                ans = mid       
                r = mid - 1     
            else:
                l = mid + 1   
                
        return ans

