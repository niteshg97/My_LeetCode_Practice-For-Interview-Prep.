class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        lo = 0
        hi = n-1
        ans = -1
        while lo <= hi:
            mid = (lo+hi)//2
            if (nums[mid] == target):
                ans = mid
                hi = mid -1 

            elif(nums[mid]>target):
                hi = mid-1
            else:
                lo = mid+1
        return ans 
        