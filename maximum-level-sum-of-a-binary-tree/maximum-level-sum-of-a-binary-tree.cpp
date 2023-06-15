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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=INT_MIN, lvl=0, ans=lvl;
        while (!q.empty()) {
            lvl++;
            int count=0, size=q.size();
            for (int i=0; i<size; ++i) {
                TreeNode* cur=q.front(); q.pop();
                count+=cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (count>sum) {
                sum=count;
                ans=lvl;
            }
        }
        return ans;
    }
};