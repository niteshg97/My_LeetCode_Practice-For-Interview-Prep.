/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // m:2 Tortoise and the Here method 
 // first detect the loop and then find the statring Node 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;

            }
            return slow;
        }

       }
       return NULL;
        
    }
};