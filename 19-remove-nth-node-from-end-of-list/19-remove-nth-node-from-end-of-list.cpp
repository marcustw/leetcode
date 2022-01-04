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
        //Placing slow and fast pointers both at the head
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre;
        //Let fast pointer take a n-1 node lead in the beginning
        for(int i=1;i<=n-1;i++){
           fast = fast->next;
        }
        //Now, let both slow and fast travel forward until fast->next == NULL
        while(fast->next !=NULL ){
           pre = slow;
           slow = slow->next;
           fast = fast->next;
        }

        //Handing the case when slow is at the head
        if(slow==head){
           head = head->next;
           return head;
        }

        //That's it, slow is in the required place (nth node from the end)
        //Which means pre is one node before slow
        pre->next = pre->next->next;
        return head;
    }
};