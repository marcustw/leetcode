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
    unordered_set<int> s;
    
    bool recurse(TreeNode* node, int k) {
        if (node == NULL) return false;
        if (s.count(k - node->val) > 0) return true;
        s.insert(node->val);
        return recurse(node->left, k) || recurse(node->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        s.insert(root->val);
        return recurse(root->left, k) || recurse(root->right, k);
    }
};