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
    vector<int> ans;

    int dfs(TreeNode* node, TreeNode* target, int k, int depth) {
        if (!node) return 0;
        if (depth==k) {
            ans.push_back(node->val);
            return 0;
        }
        int left, right;
        if (node->val == target->val || depth>0) {
            left = dfs(node->left, target, k, depth+1);
            right = dfs(node->right, target, k, depth+1);
        } else {
            left = dfs(node->left, target, k, depth);
            right = dfs(node->right, target, k, depth);
        }
        if (node->val==target->val) return 1;
        if (left==k || right==k) {
            ans.push_back(node->val);
            return 0;
        }
        if (left>0) {
            dfs(node->right, target, k, left+1);
            return left+1;
        }
        if (right>0) {
            dfs(node->left, target, k, right+1);
            return right+1;
        }
        return 0;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k==0) ans.push_back(target->val);
        else dfs(root, target, k, 0);
        return ans;
    }
};