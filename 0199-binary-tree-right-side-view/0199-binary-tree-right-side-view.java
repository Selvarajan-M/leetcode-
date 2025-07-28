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
    public List<Integer> rightSideView(TreeNode root) {
        ArrayList<Integer>ans= new ArrayList<>();
        recursion(root,0,ans);
        return ans;
    }
    public void recursion(TreeNode root, int level, ArrayList<Integer>ans){
        if(root == null){
            return;
        }
        if(level == ans.size()){
            ans.add(root.val);
        }
        recursion(root.right,level+1,ans);
        recursion(root.left,level+1,ans);
    }
}