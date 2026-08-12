class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r  = len(nums) -1 
        ans = float('inf')
        while (l<=r):
            mid = (l+r) // 2
            # left sorted part
            if(nums[mid]>=nums[l]):
                ans = min(ans,nums[l])
                l = mid+1
            else: # right part is sorted..
                r = mid -1 
                ans = min(ans, nums[mid])

        return ans 


        