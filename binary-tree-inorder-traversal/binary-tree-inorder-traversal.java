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
import java.util.*;

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Stack<TreeNode> stek = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stek.isEmpty()) {
            while (curr != null) {
                stek.push(curr);
                curr = curr.left;
            }
            TreeNode n = stek.pop();
            res.add(n.val);
            curr = n.right;
        }
        return res;
    }
}