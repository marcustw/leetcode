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
    int ans=0;
    
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        ans=max(ans,left+right);
        
        return max(left,right)+1;
    }
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return ans;
    }
};