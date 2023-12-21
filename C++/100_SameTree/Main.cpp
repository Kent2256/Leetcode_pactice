class Solution {
public:
    void preorder(TreeNode* head, vector<int>& list){
        if(not head) return;
        preorder(head->left,list);
        list.push_back(head->val);
        preorder(head->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p_list,q_lsit;
        preorder(p,p_list);
        preorder(q,q_list);
        return p_list == q_list;
    }
};