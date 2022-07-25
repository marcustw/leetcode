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
        if (!head || !head->next) return head;
        ListNode* cur=head;
        ListNode* cur2=head;
        while (cur2 && cur2->next) {
            cur=cur->next;
            cur2=cur2->next->next;
        }
        return cur;
    }
};