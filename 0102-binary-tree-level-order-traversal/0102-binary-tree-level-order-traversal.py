# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if(root==None):
            return result
        q = deque()
        q.append(root)
        while (q):
            ans = []
            n = len(q)
            while(n):
                node = q[0]
                q.popleft()
                ans.append(node.val)
                if(node.left != None ):
                    q.append(node.left)
                if(node.right != None):
                    q.append(node.right)
                n-=1
            result.append(ans)
                
        return result 
                    





        
         
        