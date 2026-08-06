class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        my_set = set()
        # Add all the elements in mySet ...
        n = len(nums)
        for i in range (0, n):
            my_set.add(nums[i])
        # traverse in the set and ccheck the prev elements
        longest = 0
        for val in my_set:
            if (val - 1) not in my_set:
                x = val
                count = 1
                while x + 1 in my_set:
                    count += 1
                    x += 1
                longest = max(longest, count)

        return longest
