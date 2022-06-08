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
private:
    vector<vector<int>> ans;
    
    void recurse(TreeNode* root, int level) {
        if (!root) return;
        while (ans.size()<=level) {
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        recurse(root->left,level+1);
        recurse(root->right,level+1);
        
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        recurse(root, 0);
        return ans;
    }
};