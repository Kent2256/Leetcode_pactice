Given the root of a binary tree and an integer targetSum, 
return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, 
but it must go downwards (i.e., traveling only from parent nodes to child nodes).
Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000


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
    void rec(int &res,unordered_map<long long int,int>& map,long long int sum, TreeNode* root, const int& targetSum){
        if(!root) return;
        sum+=root->val;
        long long int diff = sum - targetSum;
        if(map.find(diff) != map.end()){
            res+= map[diff];
        }
        map[sum]++;
        rec(res, map,sum,root->left,targetSum);
        rec(res, map,sum,root->right,targetSum);
        map[sum]--;

    }
    int pathSum(TreeNode* root, int targetSum) {
      int res = 0;
      long long sum =0;
      unordered_map<long long int,int> map;
      map[sum] = 1;
      rec(res, map,sum,root,targetSum);
      return res;  
    }
};

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
int ans=0;
    void solve(TreeNode* root,long long target)
    {
        if(root==NULL)return;
        if(root->val==target)
        {
            ++ans;
        }
        solve(root->left,target-root->val);
        solve(root->right,target-root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root)
        {
            solve(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};