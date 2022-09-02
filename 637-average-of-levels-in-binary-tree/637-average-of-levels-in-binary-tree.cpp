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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long sum = 0;
            int s = q.size();
            for (int i=0; i<s; i++) {
                TreeNode* tree = q.front();
                q.pop();
                if (tree->left) q.push(tree->left);
                if (tree->right) q.push(tree->right);
                sum += tree->val;
            }
            ans.push_back((double) sum/s);
        }
        return ans;
    }
};