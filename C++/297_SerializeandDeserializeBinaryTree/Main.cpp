Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or 
memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
1,2,null null, 3,4,null,null,5,null,null
class Codec {
public:
    void makestring(TreeNode* root,string& res){
        if(root == nullptr){
            res += "null,";
            return;
        }
        res += root->val + ",";
        makestring(root->left, res);
        makestring(root->right,res);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        makestring(root,res);
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        int pos = data.find(",");
        string val = data.substr(0,pos);
        if val == 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));