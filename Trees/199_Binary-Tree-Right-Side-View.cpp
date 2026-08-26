// Level-Order Traversal ( Space: O(W) )
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);

                //  last node of curr level
                if (i == sz - 1)
                    result.push_back(front->val);
            }
        }
        return result;
    }
};

// Recursive DFS ( Space: O(H) )
class Solution {
public:
    vector<int> result;

    void dfs(TreeNode* root, int depth) {
        if (!root)
            return;
        if (depth == result.size())
            result.push_back(root->val);
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};