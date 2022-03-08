/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* first = head;
        ListNode* second = head->next;
        while (first != NULL && first->next && second != NULL && second->next != NULL) {
            if (first == second) return true;
            first = first->next;
            second = second->next->next;
        }
        return false;
    }
};