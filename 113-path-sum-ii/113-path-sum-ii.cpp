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
    vector<vector<int>> ans;
    
    void recurse(TreeNode* node, int targetSum, int sum, vector<int>& path) {
        if (!node) return;
        sum += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (targetSum == sum)
                ans.push_back(path);
        } else {
            recurse(node->left, targetSum, sum, path);
            recurse(node->right, targetSum, sum, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> init;
        recurse(root, targetSum, 0, init);
        return ans;
    }
};