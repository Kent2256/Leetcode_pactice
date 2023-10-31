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
    int BTlevel(TreeNode*root){
        if(not root)return 0;
        int left = BTlevel(root->left);
        int right = BTlevel(root->right);
        if (abs(left - right) > 1 || left == -1 || right == -1)return -1;
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(not root)return true;
        return BTlevel(root) != -1;
    }
};