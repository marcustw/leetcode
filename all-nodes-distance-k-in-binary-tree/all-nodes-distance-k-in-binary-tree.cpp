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
    unordered_map<int, int> m;
    vector<int> ans;


    int find(TreeNode* root, TreeNode* target) {
        if (!root) return -1;
        if (root==target) {
            m[root->val]=0;
            return 0;
        }
        int left=find(root->left, target);
        if (left>=0) {
            m[root->val]=left+1;
            return left+1;
        }
        int right=find(root->right, target);
        if (right>=0) {
            m[root->val]=right+1;
            return right+1;
        }
        return -1;
    }

    void dfs(TreeNode* root, TreeNode* target, int k, int len) {
        if (!root) return;
        if (m.find(root->val) != m.end()) len=m[root->val];
        if (len==k) ans.push_back(root->val);
        dfs(root->left, target, k, len+1);
        dfs(root->right, target, k, len+1);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find(root, target);
        dfs(root, target, k, m[root->val]);
        return ans;
    }
};