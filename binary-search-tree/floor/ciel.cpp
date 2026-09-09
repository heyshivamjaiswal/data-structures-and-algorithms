struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the floor of a key
    // in a Binary Search Tree (BST)
    int floorInBST(TreeNode* root, int key){
        // Initialize the floor variable
        int floor = -1;
        
        // Traverse the BST until root becomes null
        while(root){
            // If key is equal to current node value
            // then it is the floor
            if(root->val == key){
                floor = root->val;
                return floor;
            }
            
            // If key is greater than current node value
            // move right and update floor
            if(key > root->val){
                floor = root->val;
                root = root->right;
            }
            else{
                // If key is smaller, move left
                root = root->left;
            }
        }
        // Return the computed floor value
        return floor;
    }
};