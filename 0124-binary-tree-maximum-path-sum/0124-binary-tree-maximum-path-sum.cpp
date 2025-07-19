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
    int maxPathSum(TreeNode* root) {
        int maxValue=INT_MIN;
        maxPathDown(root,maxValue);
        return maxValue;
    }
private:
    int maxPathDown(TreeNode *root,int& maxValue){
        if(root == NULL) return 0;
        int leftSum=max(0,maxPathDown(root->left,maxValue));
        int rightSum= max(0, maxPathDown(root->right,maxValue));
        maxValue=max(maxValue, (leftSum+rightSum)+root->val);
        return root->val+max(leftSum,rightSum);
    }
};