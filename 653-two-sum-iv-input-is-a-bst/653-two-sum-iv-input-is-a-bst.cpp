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
    int count = 0;
    vector<int> vals;
    
    void populate(TreeNode* node) {
        if (node == NULL) return;
        vals.push_back(node->val);
        populate(node->left);
        populate(node->right);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> m;
        populate(root);
        for (int i=0; i<vals.size(); i++) {
            int x = vals[i];
            if (m.count(k - x) > 0) return true;
            m.insert(x);
        }
        return false;
    }
};