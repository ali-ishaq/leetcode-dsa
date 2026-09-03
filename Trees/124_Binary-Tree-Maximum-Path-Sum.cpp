/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxSum=INT_MIN;
    int dfs(TreeNode* node) {
        if (!node)
            return 0;
        int leftSum = max(dfs(node->left), 0);
        int rightSum = max(dfs(node->right), 0);
        maxSum = max({maxSum, node->val + leftSum + rightSum});
        return node->val + max({leftSum, rightSum, 0});
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};