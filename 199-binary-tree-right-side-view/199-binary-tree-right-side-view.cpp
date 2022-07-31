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
    
    void recurse(TreeNode* root, int level) {
        if (!root) return ;
        if (ans.size()<level) ans.push_back(root->val);
        recurse(root->right, level+1);
        recurse(root->left, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        recurse(root,1);
        return ans;
    }
};