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
    ListNode* middleNode(ListNode* head) {
        // calculating the length of the Linkedlist
        int count =0;
        ListNode* temp= head;
        while(temp!=NULL){
            count ++;
            temp=temp->next;
        }

        int midNode=(count/2)+1;
        temp=head;
        while(temp!=NULL){
            midNode=midNode-1;
            if(midNode==0) break;
            temp=temp->next;
        }
        return temp;

        
    }
};