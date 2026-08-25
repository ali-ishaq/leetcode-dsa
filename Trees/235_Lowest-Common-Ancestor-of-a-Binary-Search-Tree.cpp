/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int high = max(p->val, q->val);
        int low = min(p->val, q->val);
       
        while (true) {
            if (root->val >= low && root->val <= high) {
                return root;
            } else if (root->val < low) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
};