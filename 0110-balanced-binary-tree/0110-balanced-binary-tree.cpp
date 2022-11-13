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
    int height(TreeNode* node, int h) {
        if (node == NULL) return h;
        return max(height(node->left, h+1), height(node->right, h+1));
    } 
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        if (abs(height(root->left, 0) - height(root->right, 0)) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};