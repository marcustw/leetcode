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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head, *cur2 = head, *kth = nullptr;
        while (--k) cur=cur->next;
        kth=cur;
        cur=cur->next;
        while (cur) {
            cur=cur->next;
            cur2=cur2->next;
        }
        swap(cur2->val, kth->val);
        return head;
    }
};