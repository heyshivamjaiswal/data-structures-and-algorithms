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
   TreeNode*solve(vector<int>&postorder , vector<int>&inorder , int start , int end, int & idx){
    if(start > end) return NULL;
    int rootVal = postorder[idx];
    idx--;
    int i = end;
    for(; i>=start; i--){
        if(inorder[i] == rootVal) break;
    }
    TreeNode*root = new TreeNode(rootVal);
    root->right = solve(postorder , inorder, i+1,end ,idx);
    root->left = solve(postorder , inorder , start , i-1, idx);

    return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        return solve(postorder ,inorder, 0 , n-1, idx);
    }
};
