class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len (height)
        l = 0
        r = n-1
        maxArea = 0 
        while(l < r):
            w =  r - l
            h = min (height[l] , height[r])
            area = w*h
            maxArea = max(maxArea , area)
            if(height[l] > height[r]):
                r -=1
            else:
                l+=1
        return maxArea

        