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

 // Method_1: Stack Method 
 // traverse through. the linkedlist and put into the Stack and agin put the Elements from the stack replacing the elements in the Linkedlist: 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        stack<int>st; //FIFO-First in and the first out 
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        // again taking from the stack and putting back to the LL
        temp= head;
        while(temp!=NULL){
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
        
    }
};