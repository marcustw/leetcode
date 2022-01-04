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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            curr = curr->next;
            count++;
        }
        curr = head;
        int fromFront = count - n;
        if (fromFront == 0) {
            return head->next;
        } else {
            for (int i = 0; i < fromFront - 1; i++) {
                curr = curr->next;
            }
            curr->next = curr->next->next;
            return head;
        }
    }
};