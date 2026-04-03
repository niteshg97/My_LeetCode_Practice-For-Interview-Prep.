class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        //  length of the list
        int n = 1;  // start with 1 since we're at head already
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            n++;
        }

        //  Connect tail to head to make it circular
        temp->next = head;

        // Find the new head (n - k % n) steps from start
        k = k % n;
        int stepsToNewHead = n - k;
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            temp = temp->next;
        }

        // Step 4: Break the ring
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};