class Solution {
public:
    bool dfs(TreeNode* root, long mn, long mx) {
        if (!root)
            return true;
        if (root->val <= mn || root->val >= mx)
            return false;

        return dfs(root->left, mn, root->val) &&
               dfs(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }
};