iven the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100


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
    void build_queue(TreeNode* root, int n, long long int i, auto &pq){
        if(root==nullptr) return;
        pq.push({n,i});
        build_queue(root->left, n+1,2*i-1,pq);
        build_queue(root->right, n+1,2*i+1,pq);
        return;
    }
    int widthOfBinaryTree(TreeNode* root) {
        priority_queue<pair<int,int>> pq;
        build_queue(root,1,0,pq);
        pair<int,int> cur = {0,0};
        int res=1;
        while(!pq.empty()){
            if(cur.first != pq.top().first){
                cur = pq.top();
                pq.pop();
            }
            else{
                if(cur.second)
                res = max(res,cur.second - pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

class Solution {
public:
    void build_queue(TreeNode* root, int n, long long int i, auto &pq){
        if(root==nullptr) return;
        pq.push({n,i});
        if(i==0){
            build_queue(root->left, n+1,-1,pq);
            build_queue(root->right, n+1,1,pq);
        }
        if(i > 0){
            build_queue(root->left, n+1,2*i-1,pq);
            build_queue(root->right, n+1,2*i,pq);
        }
        if(i<0){
            build_queue(root->left, n+1,2*i,pq);
            build_queue(root->right, n+1,2*i+1,pq);
        }
        return;
    }
    int widthOfBinaryTree(TreeNode* root) {
        priority_queue<pair<int,int>> pq;
        build_queue(root,0,0,pq);
        pair<int,int> cur = {0,0};
        int res=1;
        while(!pq.empty()){
            cout << pq.top().first << ',' << pq.top().second << endl; 
            if(cur.first != pq.top().first){
                cur = pq.top();
                pq.pop();
            }
            else{
                if((cur.second < 0 && pq.top().second < 0) ||(cur.second > 0 && pq.top().second > 0)){
                    res = max(res,cur.second - pq.top().second + 1);
                }
                else res = max(res,cur.second - pq.top().second);
                pq.pop();
            }
        }
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int res=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
           int start=q.front().second;
           int end=q.back().second;
           int size=q.size();
           res=max(res,end-start+1);
           for(int i=0;i<size;i++){
               pair<TreeNode*,int>p=q.front();
               int idx=p.second-start;
               //we will use it while inserting it children
               // left child will be at idx*2+1
               //right sgild will be at iddx*2+2
               q.pop();
               if(p.first->left)q.push({p.first->left,(long long)idx*2+1});
               if(p.first->right)q.push({p.first->right,(long long )idx*2+2});
               //long long for preventing integer overflow
           }
            
        }
        return res;
    }
};
