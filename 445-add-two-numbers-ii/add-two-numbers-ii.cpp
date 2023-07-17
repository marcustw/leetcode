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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=nullptr;
        stack<ListNode*> s1, s2;
        while (l1) s1.push(l1), l1=l1->next;
        while (l2) s2.push(l2), l2=l2->next;
        int carry=0;
        while (!s1.empty() && !s2.empty()) {
            ListNode *a=s1.top(), *b=s2.top(); s1.pop(); s2.pop();
            int c=a->val+b->val+carry;
            carry=c/10; c%=10;
            ans = new ListNode(c, ans);
        }
        while (!s1.empty()) {
            ListNode* a=s1.top(); s1.pop();
            int c=a->val+carry;
            carry=c/10; c%=10;
            ans = new ListNode(c, ans);
        }
        while (!s2.empty()) {
            ListNode* a=s2.top(); s2.pop();
            int c=a->val+carry;
            carry=c/10; c%=10;
            ans = new ListNode(c, ans);
        }
        if (carry!=0) {
            ans = new ListNode(carry, ans);
        }
        return ans;
    }
};