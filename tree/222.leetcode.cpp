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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight = getHeight(root,true);
        int rightHeight = getHeight(root,false);

        if(leftHeight == rightHeight){
            return (1<<leftHeight) -1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int getHeight(TreeNode*node , bool goLeft){
        int h = 0;
        while(node){
            h++;
            node = goLeft? node->left : node->right;
        }
        return h;
    }
};

//Alternate way 
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int lh = 0, rh = 0;
        TreeNode *l = root, *r = root;
        
        while (l) { lh++; l = l->left; }
        while (r) { rh++; r = r->right; }
        
        if (lh == rh) return (1 << lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};



// Time: O(log²n) — at each level we do O(log n) work to compute heights, and recursion depth is O(log n)
// Space: O(log n) for recursion stack
