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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *cur=head, *nxt=cur->next;
        ListNode *rev=reverse(nxt);
        cur->next=NULL;
        nxt->next=cur;
        return rev;
    }
public:
    int pairSum(ListNode* head) {
        int ans=0, cur=0;
        ListNode *slow=head, *fast=head;
        while (fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        // reverse from mid-point
        ListNode *rev=reverse(slow);
        while (rev) {
            ans=max(rev->val + head->val, ans);
            rev=rev->next;
            head=head->next;
        }
        return ans;
    }
};