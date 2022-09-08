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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root==NULL) return ans;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr=curr->left;
            }
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            curr=node->right;
        }
        return ans;
    }
};