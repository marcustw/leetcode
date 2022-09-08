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
    vector<int> ans;
    
    void recurse(TreeNode* root) {
        if (root == NULL) return;
        recurse(root->left);
        ans.push_back(root->val);
        recurse(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return ans;
        recurse(root);
        return ans;
    }
};