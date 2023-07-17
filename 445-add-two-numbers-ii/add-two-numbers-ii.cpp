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
    ListNode* reverse(ListNode* ll) {
        if (ll==nullptr || ll->next==nullptr) return ll;
        ListNode *cur=ll, *nxt=ll->next;
        ListNode *rev=reverse(nxt);
        cur->next=nullptr;
        nxt->next=cur;
        return rev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=nullptr;
        l1=reverse(l1); l2=reverse(l2);
        int carry=0;
        while (l1 || l2 || carry) {
            if (l1) carry+=l1->val, l1=l1->next;
            if (l2) carry+=l2->val, l2=l2->next;
            ans=new ListNode(carry%10, ans);
            carry/=10;
        }
        return ans;
    }
};