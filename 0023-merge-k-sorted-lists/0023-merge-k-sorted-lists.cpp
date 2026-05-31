class Solution {
public:
    // Merge two sorted linked lists
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(1000);  // Dummy node
        ListNode* temp = c;
        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                temp->next = a;
                a = a->next;
            } else {
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if (a == NULL) temp->next = b;
        else temp->next = a;
        return c->next;
    }

    // Merge K sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if (arr.size() == 0) return NULL;
        while (arr.size() > 1) {
            ListNode* a = arr.back(); arr.pop_back();
            ListNode* b = arr.back(); arr.pop_back();
            ListNode* c = merge(a, b);
            arr.push_back(c);
        }
        return arr[0];
    }
};
