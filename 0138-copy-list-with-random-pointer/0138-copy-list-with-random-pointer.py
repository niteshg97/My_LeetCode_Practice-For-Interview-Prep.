"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mp = {}
        if head is None:
            return None
        # create copy of every Node
        curr = head 
        while(curr):
            mp[curr] = Node(curr.val)
            curr = curr.next
        # conect next and  random pointer 

        curr = head 
        while(curr):
            copy = mp[curr]
            copy.next = mp.get(curr.next)
            copy.random = mp.get(curr.random)  
            curr =curr.next 
        
        return mp[head]


        