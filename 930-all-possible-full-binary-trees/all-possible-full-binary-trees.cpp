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

    TreeNode* copy(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* copyRoot = new TreeNode(0);
        copyRoot->left = copy(root->left);
        copyRoot->right = copy(root->right);
        return copyRoot;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;

        if (n==1) ans.push_back(new TreeNode(0));
        else if (n%2) {
            for (int i=2; i<=n; i+=2) {
                auto left = allPossibleFBT(i-1);
                auto right = allPossibleFBT(n-i);
                for (int j=0; j<left.size(); ++j) {
                    for (int k=0; k<right.size(); ++k) {
                        ans.push_back(
                            new TreeNode(
                                0,
                                (k==right.size()-1) ? left[j] : copy(left[j]),
                                (j==left.size()-1) ? right[k] : copy(right[k])));
                    }
                }
            }
        }
        return ans;
    }
};