/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) return head;
        //originalListNode points to newListNode
        unordered_map<Node*,Node*> nodes;
        Node* cur=head;
        while (cur!=NULL) {
            nodes[cur] = new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while (cur!=NULL) {
            nodes[cur]->next = nodes[cur->next];
            nodes[cur]->random = nodes[cur->random];
            cur=cur->next;
        }
        return nodes[head];
    }
};