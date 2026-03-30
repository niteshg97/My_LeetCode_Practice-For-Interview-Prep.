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

 // method : 1 , the time complexity is O(2N) and he space complexity is O(1):
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count ==n){
            ListNode* newHead=head->next;
            return newHead;
        }
        int res=count-n;
        temp=head;
        while(temp!=NULL){
            res--;
            if(res==0) break;
            temp=temp->next;
        }
        ListNode* del=temp->next;
        temp->next=temp->next->next;
        delete del;
        return head; 
    }
};