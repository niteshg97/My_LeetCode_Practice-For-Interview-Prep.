# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root): ## Dfs 
        if root is None:
            return 0
        left = self.solve(root.left)
        right = self.solve(root.right)
        return 1 + max(left, right)
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        left = self.solve(root.left)
        right = self.solve(root.right)
        if abs(left - right) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
