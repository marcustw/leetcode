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
    int recurse(TreeNode* root, long sum) {
        if (!root) return 0;
        return (sum == root->val ? 1 : 0)
            + recurse(root->left, sum - root->val)
            + recurse(root->right, sum - root->val);
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return recurse(root, sum)
            + pathSum(root->left, sum)
            + pathSum(root->right, sum);
    }
};