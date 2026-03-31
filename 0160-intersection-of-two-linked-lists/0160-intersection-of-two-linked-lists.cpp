/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // method 2:using the one pass 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        if (headA == NULL || headB == NULL) return NULL;

        while (tempA != tempB) {
            
            if (tempA == NULL) tempA = headB;
            else tempA = tempA->next;

            if (tempB == NULL) tempB = headA;
            else tempB = tempB->next;
        }

        return tempA; 
    }
};
