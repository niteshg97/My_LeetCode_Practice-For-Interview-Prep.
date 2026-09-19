# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode | None) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        node = []
        curr = head 
        while(curr):
            node.append(curr)
            curr = curr.next 

        left = 0
        right = len(node) - 1
        while(left < right):
            node[left].next = node[right]
            left +=1
            node[right].next = node[left]
            right -= 1
        node[left].next = None