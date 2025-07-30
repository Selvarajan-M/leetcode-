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
    private void pathsfind(TreeNode root, String path, List<String>paths){
        if(root == null) return;

         if (!path.isEmpty()) {
            path += "->";
        }
        path += root.val;
        

         if (root.left == null && root.right==null) {
            paths.add(path);
        } else {
            pathsfind(root.left, path, paths);
            pathsfind(root.right, path, paths);
        }
    }
    public List<String> binaryTreePaths(TreeNode root) {
         List<String>paths = new ArrayList<>();
         pathsfind(root,"",paths);
         return paths;
    }
}