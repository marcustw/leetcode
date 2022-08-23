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
    bool hasPathSum(TreeNode* node, int targetSum, int sum) {
        if (!node) return false;
        sum+=node->val;
        if (!node->left && !node->right) return sum==targetSum;
        return hasPathSum(node->left, targetSum, sum) || hasPathSum(node->right, targetSum, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(root, targetSum, 0);
    }
};