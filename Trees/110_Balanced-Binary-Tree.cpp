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
    int mx_diff=0;
     int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);  
        mx_diff=max(mx_diff,abs(l-r));  
        return 1+max(l,r) ;
    }
    bool isBalanced(TreeNode* root) {
     dfs(root);
     return mx_diff<=1;
    }

};