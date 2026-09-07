/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string result;
       serializeHelper(root,result);
       return result; 
    }
    
    void serializeHelper(TreeNode*node, string& result){
        if(!node){
            result += "#,";
            return;
        }
        result = result + to_string(node->val)+",";
        serializeHelper(node->left, result);
        serializeHelper(node->right , result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return deserializeHelper(data,idx);
    }

    TreeNode* deserializeHelper(string & data , int & idx){
        int commaPosition = data.find(',', idx);
        string token = data.substr(idx, commaPosition-idx);
        idx = commaPosition +1;

        if(token == "#"){
            return nullptr;[]
        }
        TreeNode*node = new TreeNode(stoi(token));
        node->left = deserializeHelper(data, idx);
        node->right = deserializeHelper(data, idx);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));




// (imagine idx pointing at the start of each token as we go)

// Call 1: deserializeHelper(data, idx=0)

// Read token at idx=0 → "1". Not #, so this is a real node. Advance idx past it.
// Create node = TreeNode(1).
// Now we need node->left. We don't know in advance how many tokens belong to node 1's left subtree — we just call deserializeHelper again right now, and whatever it consumes, however many tokens that takes, is entirely left's problem.

// Call 2 (this IS node(1)->left): deserializeHelper(data, idx=2)

// Read token → "2". Not #. Create node = TreeNode(2). Advance idx.
// Need node(2)->left → recurse again.

// Call 3 (this is node(2)->left): deserializeHelper(data, idx=4)

// Read token → "#". This is the signal to stop. Return nullptr immediately. Advance idx past the #.
// Back in Call 2: node(2)->left = nullptr. ✓ Done with that branch.

// Call 2 continues — now needs node(2)->right → recurse.

// Call 4 (this is node(2)->right): deserializeHelper(data, idx=6)

// Read token → "#". Return nullptr. Advance idx.
// Back in Call 2: node(2)->right = nullptr.

// Call 2 is now fully done (both children set) → returns node(2) back up to Call 1.

// Back in Call 1: node(1)->left = node(2) (with its whole subtree already attached). ✓

// Notice what just happened: Call 1 never needed to know "left subtree occupies tokens 2 through 6." It just said "go build me a subtree starting from wherever idx currently is" — and trusted that whatever comes back has correctly consumed exactly the tokens belonging to that subtree, no more, no less, because of how the # markers terminate each branch.

// Call 1 continues — now needs node(1)->right → recurse, starting at idx=8 (wherever it currently sits after all of node(2)'s subtree was consumed).

// Call 5 (this is node(1)->right): deserializeHelper(data, idx=8)

// Read token → "3". Create node(3). Recurse for its left...
// ...(same pattern continues for 4, 5, and their nulls)...
