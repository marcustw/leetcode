/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Stack<TreeNode> stek = new Stack<>();
        stek.push(root);
        while (!stek.isEmpty()) {
            TreeNode n = stek.pop();
            if (n != null) {
                res.add(n.val);
                stek.push(n.right);
                stek.push(n.left);
            }
            
        }
        return res;
    }
}