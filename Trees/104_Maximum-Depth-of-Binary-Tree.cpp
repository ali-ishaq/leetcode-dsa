// BFS Approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            int size=q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            depth++;
        }
        return depth;
    }
};

// Recursive DFS Approach
class Solution {
public:
 int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
}