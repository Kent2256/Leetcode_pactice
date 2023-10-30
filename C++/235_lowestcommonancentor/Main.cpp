/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(not root)return nullptr;
        if ((root->val == p-> val) || (root->val == q->val))return root;
        TreeNode* left_result = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_result =lowestCommonAncestor(root->right,p,q);
        if (left_result and right_result)return root;
        else if(left_result) return left_result;
        else if(left_result) return right_result;
        return nullptr;
    }
};