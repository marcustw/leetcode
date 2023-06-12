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
    ListNode* getMid(ListNode* head) {
        ListNode *cur=head, *next=head, *prev=NULL;
        while (next && next->next) {
            prev=cur;
            cur=cur->next;
            next=next->next->next;
        }
        prev->next=NULL;
        return cur;
    }

    ListNode* reverse(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *cur=head, *nxt=cur->next, *rev=reverse(nxt);
        cur->next=NULL;
        nxt->next=cur;
        return rev; 
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL) return true;
        ListNode* mid = reverse(getMid(head));
        while (head) {
            if (head->val != mid->val) return false;
            head=head->next;
            mid=mid->next;
        }
        return true;
    }
};