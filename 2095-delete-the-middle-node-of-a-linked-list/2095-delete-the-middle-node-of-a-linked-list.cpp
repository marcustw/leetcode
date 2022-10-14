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
        if (!head || !head->next) return NULL;
        if (!head->next->next) {
            head->next = NULL;
            return head;
        }
        ListNode* temp = head;
        ListNode* cur = head->next;
        ListNode* jump = head->next;
        while (jump && jump->next) {
            temp = temp->next;
            cur = cur->next;
            jump = jump->next->next;
        }
        if (!jump) {
            *temp = *cur;
        } else {
            temp = cur->next;
            *cur = *temp;
        }
        
        return head;
    }
};