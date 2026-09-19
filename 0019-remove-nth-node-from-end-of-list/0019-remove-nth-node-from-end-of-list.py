# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        if head is None:
            return 
        node = []
        curr = head 
        while (curr is not None):
            node.append(curr)
            curr = curr.next
        remove_idx = len(node) - n
        if (remove_idx == 0):
            return head.next
        previous = node[remove_idx - 1]
        previous.next = previous.next.next
        return head
        

        
        