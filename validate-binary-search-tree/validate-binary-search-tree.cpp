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
    bool isValidBST(TreeNode* node, long left, long right) {
        if (!node) return true;
        if (node->val <= left || node->val >= right) return false;
        return isValidBST(node->left, left, node->val) && isValidBST(node->right, node->val, right);
    }

public:
    bool isValidBST(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};