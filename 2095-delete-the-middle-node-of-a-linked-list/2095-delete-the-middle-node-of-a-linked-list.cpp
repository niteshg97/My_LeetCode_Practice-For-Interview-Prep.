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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;

        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (head->next == NULL) return NULL;

        int res = count / 2;
        temp = head;

        while (temp != NULL) {
            res--;
            if (res == 0) break;
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};
