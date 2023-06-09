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
    ListNode* getMid(ListNode* head) {
        ListNode* prev = new ListNode(0, head);
        while (head && head->next) {
            prev = prev->next;
            head = head->next->next;
        }
        ListNode* mid = prev->next;
        prev->next = nullptr;
        return mid;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0, nullptr), *cur=ans;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return ans->next;
    }
public:
    Solution() {
        ios_base::sync_with_stdio(0);
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        return merge(sortList(head), sortList(mid));
    }
};