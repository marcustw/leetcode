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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        if (head->val == val) {
            ListNode* temp = head->next;
            delete head;
            return removeElements(temp, val);
        }
        ListNode* cur = head;
        ListNode* prev = cur;
        while (cur) {
            if (cur->val == val) {
                cur = cur->next;
                prev->next = cur;
            } else {
                prev = cur;
                cur = cur->next; 
            }
        }
        return head;
    }
};