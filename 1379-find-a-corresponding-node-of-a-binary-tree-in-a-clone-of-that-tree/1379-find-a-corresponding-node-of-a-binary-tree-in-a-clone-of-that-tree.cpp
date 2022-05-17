/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //Follow up: Could you solve the problem if repeated values on the tree are allowed?
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == NULL) return NULL;
        else if (original == target) return cloned;
        
        TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
        TreeNode* rightResult = getTargetCopy(original->right, cloned->right, target);
        
        return leftResult == NULL ? rightResult : leftResult;
    }
};