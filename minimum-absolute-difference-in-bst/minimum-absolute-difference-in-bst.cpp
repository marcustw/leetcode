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
    // binary search tree -> sorted order
    // minDiff definitely comes from abs(parent->val - child->val)
    int getMinimumDifference(TreeNode* root) {      
        // iterative
        int ans=INT_MAX, val=-1;
        stack<TreeNode*> stek;
        while (root || !stek.empty()) {
            while (root) {
                stek.push(root);
                root=root->left;
            }
            root=stek.top();
            stek.pop();
            if (val>=0) ans=min(ans, root->val-val);
            val=root->val;
            root=root->right;
        }
        return ans;
    }
};