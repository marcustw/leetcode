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
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode* head1 = head;
        ListNode* head2 = head;
        
        while (head1->next != NULL && head2->next != NULL && head2->next->next != NULL) {
            head1 = head1->next;
            head2 = head2->next->next;
            if (head1 == head2) {
                return true;
            }
        }
        return false;
    } 
};