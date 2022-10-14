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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head) return head;
        if (!head->next) {
            delete head;
            return NULL;
        }
        ListNode* cur = head;
        ListNode* jump = head;
        ListNode* temp = head;
        while (jump && jump->next) {
            if (cur!=head) temp = temp->next;
            cur = cur->next;
            jump = jump->next->next;
        }
        temp->next = cur->next;
        delete cur;
        return head;
    }
};