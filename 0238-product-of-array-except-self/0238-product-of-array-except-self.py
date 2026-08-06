class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)

        prefix = 1
        for i in range(len(nums)): # {traverse from start to end}
            res[i] = prefix
            prefix *= nums[i]

        postfix = 1
        for i in range(len(nums)-1, -1, -1): # {Traverse the array from end to start}
            res[i] *= postfix
            postfix *= nums[i]

        return res



        