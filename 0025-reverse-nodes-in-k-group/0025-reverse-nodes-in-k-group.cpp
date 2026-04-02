/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Helper to reverse a portion of the list
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;

        while (prev != tail) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return tail; // new head after reversal
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while (true) {
            // Find the kth node
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) break; // not enough nodes

            ListNode* groupNext = kth->next;
            // Reverse this group
            ListNode* groupStart = groupPrev->next;
            reverse(groupStart, kth);
            // Reconnect
            groupPrev->next = kth;
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
