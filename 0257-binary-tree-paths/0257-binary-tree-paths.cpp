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
    void pathsfind(TreeNode* root, string path, vector<string>&paths){
        if(!root) return;

         if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);
        

         if (!root->left && !root->right) {
            paths.push_back(path);
        } else {
            pathsfind(root->left, path, paths);
            pathsfind(root->right, path, paths);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>paths;
         pathsfind(root,"",paths);
         return paths;
    }
};