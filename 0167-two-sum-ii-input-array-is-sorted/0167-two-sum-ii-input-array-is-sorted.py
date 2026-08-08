class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0 
        n = len(numbers) -1 
        r = n
        ans = []
        while (l<=r):
            mid  =  (l + r) / 2
            total = numbers[l] + numbers[r]
            if(total == target):
                return[l+1 , r+1]
            elif( total > target):
                r -= 1
            else:
                l +=1
        return []
            


        