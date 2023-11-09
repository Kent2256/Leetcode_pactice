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
// preorder: cur->left->right
// inorder: left->current->right
//preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
//      3
//     9 20
//      15 7
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int,int> map;
    TreeNode* constructTree(vector<int>& preorder, int& index ,int left, int right){
        if(index >= preorder.size() || left>right)return nullptr;
        int cur_val = preorder[index];
        int pos = map[cur_val];
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = constructTree(preorder,index,left, pos -1);
        root->right = constructTree(preorder,index,pos +1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0){
            return nullptr;
        }
        int index = 0;
        int n = inorder.size();
        for( int i = 0; i < n;i ++){
            map[inorder[i]] = i;
        }
        return constructTree(preorder, index, 0, preorder.size());
    }
};