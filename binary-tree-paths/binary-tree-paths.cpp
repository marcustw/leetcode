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
    vector<string> ans;

    void dfs(TreeNode* node, string path) {
        if (!node) return;
        path += "->" + to_string(node->val);
        if (!node->left && !node->right) {
            ans.push_back(path);
            return;
        }
        dfs(node->left, path);
        dfs(node->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return ans;
        string path=to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(path);
            return ans;
        }
        dfs(root->left, path);
        dfs(root->right, path);
        return ans;
    }
};