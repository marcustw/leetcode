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
    int goodNodes(TreeNode* node, int pathMax) {
        if (node == NULL) return 0;
        int ans = node->val >= pathMax ? 1 : 0;
        int newPathMax = max(pathMax, node->val);
        return ans + goodNodes(node->left, newPathMax)
            + goodNodes(node->right, newPathMax);
    }
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, root->val);
    }
};