vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;   // empty vector for empty tree

    res.push_back(root->val);                          // visit root

    vector<int> leftResult = preorderTraversal(root->left);   // get left's answer
    vector<int> rightResult = preorderTraversal(root->right); // get right's answer

    for (int v : leftResult)  res.push_back(v);   // staple it on
    for (int v : rightResult) res.push_back(v);

    return res;
}
