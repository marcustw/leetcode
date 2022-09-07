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
public:
    string tree2str(TreeNode* root) {
        //dfs
        if (root==NULL) return "";
        string lefts = "(";
        string rights = "(";
        if (root->left) lefts += tree2str(root->left);
        if (root->right) rights += tree2str(root->right);
        lefts += ")";
        rights += ")";
        if (lefts == "()" && rights == "()") return to_string(root->val);
        if (rights == "()") rights = "";
        return to_string(root->val) + lefts + rights;
    }
};