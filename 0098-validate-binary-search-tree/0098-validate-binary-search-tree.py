# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def solve(temp, low, high):
            if temp == None:
                return True
            if not (low < temp.val < high):
                return False

            return solve(temp.left, low, temp.val) and solve(temp.right, temp.val, high)

        return solve(root, float("-inf"), float("inf"))
