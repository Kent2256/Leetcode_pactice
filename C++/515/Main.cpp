Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1

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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int prev_level=0;
        int local_max = INT_MIN;
        vector<int> result;
        while(!q.empty()){
            auto[cur, level] = q.front();
            q.pop();
            if(prev_level!=level){
                result.push_back(local_max);
                prev_level = level;
                local_max = INT_MIN;
            }
            local_max = max(cur->val,local_max);
            if(cur->left!=nullptr)q.push({cur->left,level+1});
            if(cur->right!=nullptr)q.push({cur->right,level+1});
        }
        result.push_back(local_max);
        return result;
    }
};