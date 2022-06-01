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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root==p || root==q) return  root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        
        //if LCA not at the left, it must be at the right
        if (left==NULL) return right;
        
        //if LCA not at the right, it must be at the left
        else if (right==NULL) return left;
        
        //if "LCAs" are found in both left and right
        //then there exist an LCA=root that is ancestor of both
        //left and right!
        return root;
    }
};