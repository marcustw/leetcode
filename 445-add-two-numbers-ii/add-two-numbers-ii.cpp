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
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) carry+=s1.top()->val, s1.pop();
            if (!s2.empty()) carry+=s2.top()->val, s2.pop();
            ans = new ListNode(carry%10, ans);
            carry/=10;
        }
        if (carry!=0) {
            ans = new ListNode(carry, ans);
        }
        return ans;
    }
};