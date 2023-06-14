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
    // binary search tree
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val==key) {
            if (!root->left && !root->right) return NULL;
            if (!root->left || !root->right) return root->left ? root->left : root->right;
            TreeNode* cur=root->left;
            while (cur->right) cur=cur->right;
            root->val=cur->val;
            root->left = deleteNode(root->left, cur->val);
        } else if (root->val<key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};