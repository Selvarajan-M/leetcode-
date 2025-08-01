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
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();;
        if(root==null) return ans;
        Queue<TreeNode>q=new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int size=q.size();
            List<Integer>level=new LinkedList<Integer>();
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll(); // remove the front node

                level.add(node.val); // add its value

                if (node.left != null) q.offer(node.left);  // enqueue left child
                if (node.right != null) q.offer(node.right); // enqueue right child
            }
           ans.add(level);
        }
        return ans;
    }
}