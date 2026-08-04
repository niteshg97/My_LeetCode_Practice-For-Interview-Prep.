## Method -1 using the hashMap
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {} # num , Index
        for i , num in  enumerate(nums):
            diff = target - num
            if diff in mp:
                return [mp[diff], i]

            mp[num] =  i ## agar nahi hai toh map me num and its index daal do 
            





        