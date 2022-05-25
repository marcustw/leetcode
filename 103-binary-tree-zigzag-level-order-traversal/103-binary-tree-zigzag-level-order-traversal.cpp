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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> ans;
        vector<int> bfs;
        queue<TreeNode*> q;
        int height=0;
        q.push(root);
        while (q.empty() == false) {
            int l = q.size();
            vector<int> arr(l);
            bool dir = height%2==0;
            for (int i=0; i<l; i++) {
                TreeNode* first = q.front();
                if (dir) {
                    // left to right
                    arr[i] = first->val;
                    
                } else {
                    // right to left
                    arr[l-i-1] = first->val;
                    
                }
                q.pop();
                if (first->left != NULL) {
                    q.push(first->left);
                }
                if (first->right != NULL) {
                    q.push(first->right);
                }
            }
            ans.push_back(arr);
            height++;
        }
        return ans;
    }
};