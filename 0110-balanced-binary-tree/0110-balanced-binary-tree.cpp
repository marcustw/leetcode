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
        int left = height(node->left, h+1);
        int right = height(node->right, h+1);
        if (left == -1 || right == -1 || abs(left-right) > 1) return -1;
        return max(left, right);
    } 
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return height(root, 0) != -1;
    }
};