vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;   // empty tree, empty answer

    queue<TreeNode*> q;
    q.push(root);          // start with just the root in the queue

    while (!q.empty()) {
        int levelSize = q.size();     // <-- the critical trick, explained below
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            currentLevel.push_back(node->val);

            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        res.push_back(currentLevel);
    }

    return res;
}
