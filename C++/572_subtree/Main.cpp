class Solution {
public:
    bool isSametree(TreeNode* p, TreeNode* q){
        if((p!=nullptr && q==nullptr)||(p==nullptr && q!=nullptr))return false;
        if(p==nullptr && q==nullptr)return true;
        if(p->val != q->val)return false;
        return isSametree(p->right,q->right) && isSametree(p->left,q->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(root->val == subRoot->val){
            if(isSametree(root,subRoot))return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};