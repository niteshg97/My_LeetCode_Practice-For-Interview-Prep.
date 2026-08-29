# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        def dfs(node, maxVal):
            if not node:
                return 0
            count = 0
            if node.val >= maxVal:
                count = 1
            maxVal = max(maxVal, node.val)
            # Count good nodes in left and right subtree
            left = dfs(node.left, maxVal)
            right = dfs(node.right, maxVal)
            return count + left + right

        return dfs(root, root.val)




         
        
        