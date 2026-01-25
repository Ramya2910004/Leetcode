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
    ListNode* reversell(ListNode* head){
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr!=NULL){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=reversell(slow->next);
        ListNode* first=head;
        ListNode* second=rev;
        while(second!=NULL){
            if(first->val!=second->val){
                reversell(rev); // restoring original linked list before exiting        because  it is not good to change original input list.
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reversell(rev);
        return true;
    }
};