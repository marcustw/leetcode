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
    ListNode* reverseList(ListNode* head) {
        // Recursive
        if (head==NULL || head->next==NULL) return head;
        ListNode* cur=head;
        ListNode* nxt=cur->next;
        ListNode* rev=reverseList(nxt);
        cur->next=NULL;
        nxt->next=cur;
        return rev;
    }

    ListNode* reverseListIterative(ListNode* head) {
        // Iterative
        ListNode *nextNode = nullptr, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};