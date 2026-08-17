from collections import deque

class Solution:
    def maxSlidingWindow(self, nums, k):
        dq = deque()
        ans = []
        for r in range(len(nums)):
            if dq and dq[0] <= r - k:
                dq.popleft()
                #Remove smaller values from the back
            while dq and nums[dq[-1]] < nums[r]:
                dq.pop()

            # 3. Add current index
            dq.append(r)

            # 4. Window is ready
            if r >= k - 1:
                ans.append(nums[dq[0]])

        return ans

        