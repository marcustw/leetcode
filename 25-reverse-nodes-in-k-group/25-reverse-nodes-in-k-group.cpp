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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        for (int i=0; i<k; i++) {
            if (curr==NULL) return head;
            curr=curr->next;
        }
        ListNode* rear=reverseKGroup(curr,k);
        
        ListNode* prev=rear;
        ListNode* next=head;
        
        for (int i=0; i<k-1; i++) {
            ListNode* temp=next->next;
            //next point to prev
            next->next=prev;
            //prev = next;
            prev=next;
            //next = next-> next;
            next=temp;
        }
        next->next=prev;
        return next;
    }
};