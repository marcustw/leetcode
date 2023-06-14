/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        priority_queue<int> pq;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node=st.top();
            st.pop();
            pq.push(node->val);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        int cur=pq.top(); pq.pop();
        while (!pq.empty()) {
            if (abs(pq.top()-cur)<ans) ans=abs(pq.top()-cur);
            cur=pq.top();
            pq.pop();
        }
        return ans;
    }
};