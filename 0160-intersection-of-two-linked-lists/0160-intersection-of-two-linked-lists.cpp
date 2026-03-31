/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // method 1: using the HashMap Data structure 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int>mp;
        ListNode*tempA=headA;
        ListNode* tempB=headB;
        while( tempA!=NULL){
            mp[tempA]++;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            if(mp.find(tempB)!=mp.end()){
                return tempB;
            }
            tempB=tempB->next;
        }
        return NULL;
        
        
    }
};