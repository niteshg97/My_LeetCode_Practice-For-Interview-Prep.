# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:

        if list1 is None and list2 is None:
            return None

        if list1 is None:
            return list2

        if list2 is None:
            return list1

        if(list1.val <= list2.val):
            res = list1
            res.next= self.mergeTwoLists(list1.next , list2)
            return res
        else:
            res = list2
            res.next = self.mergeTwoLists(list1 , list2.next)
            return res

        

