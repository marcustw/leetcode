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
    TreeNode* recurse(vector<int>& nums, int lo, int hi) {
        int partition = lo + (hi-lo)/2;
        if (partition<0 || partition>=nums.size() || partition<lo || partition>hi) return NULL;
        return new TreeNode(nums[partition], recurse(nums, lo, partition-1), recurse(nums, partition+1, hi));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums,0,nums.size()-1);
    }
};