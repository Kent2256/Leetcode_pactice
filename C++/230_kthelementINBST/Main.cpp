class Solution {
public:
    int findBST(TreeNode* root, int &cur,int k){
        if(root==nullptr)return -1;
        int res = findBST(root->left,cur,k);
        if(cur == k)return res;
        cur++;
        res=root->val;
        if(cur == k)return res;
        return findBST(root->right,cur,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        return findBST(root,cur,k);
    }
};