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

struct Node {
    ListNode* cur; // next = cur->next
    Node* prev;

    Node(ListNode* cur): cur(cur), prev(nullptr) {} 
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head;
        Node* front = new Node(cur);
        Node* rear = front;
        while (rear->cur) {
            Node* newRear = new Node(rear->cur->next);
            newRear->prev = rear;
            rear = newRear;
        }
        rear = rear->prev;
        while (k-->1) {
            cur = cur->next;
            rear = rear->prev;
        }
        swap(cur->val, rear->cur->val);
        return head;
    }
};