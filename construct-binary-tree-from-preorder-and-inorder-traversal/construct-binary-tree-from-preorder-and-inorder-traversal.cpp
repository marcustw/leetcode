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
    map<int, int> m;
public:
    Solution() { ios::sync_with_stdio(false); }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl>pr || il>ir || pl>=preorder.size() || pr>=preorder.size() || pl<0 || pr<0) return NULL;
        TreeNode* newNode = new TreeNode(preorder[pl]);
        int inorder_index=m[preorder[pl]];
        int left_size=inorder_index-il;
        newNode->left = buildTree(preorder, inorder, pl+1, pl+left_size, il, inorder_index-1);
        newNode->right = buildTree(preorder, inorder, pl+left_size+1, pr, inorder_index+1, ir);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for (int i=0; i<n; ++i) {
            m[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};

// preorder = [3,9,10,11,20,15,7]
// inorder = [10,9,11,3,15,20,7]