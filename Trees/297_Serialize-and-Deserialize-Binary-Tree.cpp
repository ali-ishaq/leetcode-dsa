class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if (top) {
                q.push(top->left);
                q.push(top->right);
                s.append(to_string(top->val) + ",");
            } else {
                s.append("NULL,");
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;

        // Read first token (root)
        getline(ss, val, ',');
        if (val == "NULL" || val.empty())
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(ss, val, ',')) {
                if (val != "NULL") {
                    TreeNode* leftNode = new TreeNode(stoi(val));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Right child
            if (getline(ss, val, ',')) {
                if (val != "NULL") {
                    TreeNode* rightNode = new TreeNode(stoi(val));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }
};
