class Solution {
    TreeNode* solve(vector<int>& preorder, int prestart, int preend,
                    vector<int>& inorder, int instart, int inend,
                    map<int, int>& inmap) {

        if (prestart > preend || instart > inend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inroot = inmap[root->val];
        int numsleft = inroot - instart;

        root->left = solve(preorder, prestart + 1, prestart + numsleft, inorder,
                           instart, inroot - 1, inmap);

        root->right = solve(preorder, prestart + numsleft + 1, preend, inorder,
                            inroot + 1, inend, inmap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        map<int, int> inmap;
        for (int i = 0; i < n; i++) {
            inmap[inorder[i]] = i;
        }

        TreeNode* root = solve(preorder, 0, n - 1, inorder, 0, n - 1, inmap);

        return root;
    }
};