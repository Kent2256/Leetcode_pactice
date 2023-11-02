class Solution {
public:
    int diameter;
    int longestPath(TreeNode* node){
        if(node==NULL) return 0;
        int leftPath = longestPath(node->left);
        int rightPath = longestPath(node->right);
        diameter = max(diameter, leftPath+rightPath);
        return max(leftPath, rightPath) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        longestPath(root);
        return diameter;
    }
};