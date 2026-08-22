# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self , root , subRoot):
        if not root and not subRoot:
            return True 
        if root and subRoot and (root.val != subRoot.val):
            return False
        if not root or not subRoot:
            return False
        return self.solve(root.left,subRoot.left) and self.solve(root.right,subRoot.right)
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root and not subRoot:
            return True
        if not root or not subRoot:
            return False
        if self.solve(root,subRoot):
            return True
        return self.isSubtree(root.left,subRoot) or self.isSubtree(root.right,subRoot)
    