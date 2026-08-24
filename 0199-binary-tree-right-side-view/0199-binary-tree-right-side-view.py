# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if( root == None):
            return result
        q = deque()
        q.append(root)
        while(q):
            n  = len(q)
            node = None
            while(n):
                node = q.popleft()
                if node.left is not None:
                    q.append(node.left)
                if node.right is not None:
                    q.append(node.right)
                n = n - 1 
            result.append(node.val)
        return result
        




        
        