class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Always binary search on the smaller array
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        m = len(nums1)
        n = len(nums2)
        l = 0
        r = m
        while l <= r:

            partition1 = (l + r) // 2
            partition2 = (m + n + 1) // 2 - partition1

            # Left and right values
            if partition1 == 0:
                left1 = float('-inf')
            else:
                left1 = nums1[partition1 - 1]

            if partition1 == m:
                right1 = float('inf')
            else:
                right1 = nums1[partition1]

            if partition2 == 0:
                left2 = float('-inf')
            else:
                left2 = nums2[partition2 - 1]

            if partition2 == n:
                right2 = float('inf')
            else:
                right2 = nums2[partition2]

            # Correct partition
            if left1 <= right2 and left2 <= right1:
                # Odd
                if (m + n) % 2 == 1:
                    return max(left1, left2)
                # Even
                else:
                    return (max(left1, left2) +
                         min(right1, right2)) / 2
            # We took too many elements from nums1
            elif left1 > right2:
                r = partition1 - 1
            # We took too few elements from nums1
            else:
                l = partition1 + 1


