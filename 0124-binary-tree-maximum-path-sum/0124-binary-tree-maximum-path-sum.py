# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        maxSum = float("-inf") # make sure to strat with the negative infinity ..
        def Solve(node):
            nonlocal maxSum 
            if node is None:
                return 0
            left = Solve(node.left)
            right = Solve(node.right)

            summ1 = left + right + node.val #case - 1
            summ2 = max(left, right) + node.val # case - 2
            summ3 = node.val # case - 3
            maxSum = max(maxSum, summ1, summ2, summ3)

            return max(summ2, summ3)

        Solve(root)

        return maxSum
