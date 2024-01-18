Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
'
3
9 20
7 15

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        vector<int> sub;
        vector<TreeNode*> st;
        vector<TreeNode*> st_next;
        st.push_back(root);
        int dir =0;
        while(!st.empty()){
            sub.clear();
            int n = st.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = st.back();
                st.pop_back();
                sub.push_back(temp->val);
                if(dir == 0){
                    if(temp->left) st_next.push_back(temp->left);
                    if(temp->right) st_next.push_back(temp->right);
                }
                else{
                    if(temp->right) st_next.push_back(temp->right);
                    if(temp->left) st_next.push_back(temp->left);
                }
            }
            ++dir%=2;
            result.push_back(sub);
            st=st_next;
            st_next.clear();
        }
        return result;
    }
};