Given a binary tree where node values are digits from 1 to 9. 
A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values 
in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

 

Example 1:
   2
  3 1
3 1   1



Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. 
There are three paths going from the root node to leaf nodes: 
the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. 
Among these paths only red path and green path are pseudo-palindromic 
paths since the red path [2,3,3] can be rearranged in 
[3,2,3] (palindrome) 
and the green path [2,1,1] 
can be rearranged in [1,2,1] (palindrome).
Example 2:



Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1

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
    void dfs(TreeNode* root, vector<int> &map, int& single_flag, int &total_num, int &result){
        if(!root)return;
        map[root->val]++;
        if(map[root->val]%2==1)single_flag++;
        else single_flag--;
        total_num++;
        if(!root->left && !root->right){
            if((single_flag==1 && total_num%2==1) || (single_flag==0 && total_num%2 ==0)){
                result++;
            }
        }
        dfs(root->left,map,single_flag,total_num,result);
        dfs(root->right,map,single_flag,total_num,result);
        map[root->val]--;
        if(map[root->val]%2==1)single_flag++;
        else single_flag--;
        total_num--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int single_flag=0;
        int total_num=0;
        int result=0;
        vector<int> map(10,0);
        dfs(root,map,single_flag,total_num,result);
        return result;
    }
};