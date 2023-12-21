//Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

class Solution {
public:
    unordered_map<int,vector<int>> map;
    void pushbylevel(TreeNode* root, int level){
        if(root==nullptr) return;
        map[level].push_back(root->val);
        pushbylevel(root->left,res,level+1);
        pushbylevel(root->right,res,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       int level = 0;
       vector<vector<int>> res;
       pushbylevel(root,0);
       while(map.find(level)!=map.end()){
            res.push_back(map(level));
            level++;
       }
       return res;
    }
};
/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         queue<TreeNode*> levelQueue;
         vector<vector<int>>ans;
         levelQueue.push(root);
         while(!levelQueue.empty()){
             int levelSize=levelQueue.size();
             int i=0;
             vector<int> subvector;
             while(i<levelSize){
             TreeNode *x=levelQueue.front();
             levelQueue.pop();
             if(x!=NULL){
             subvector.push_back(x->val);
             levelQueue.push(x->left);
             levelQueue.push(x->right);
             }
             i++;
             }
             if(!subvector.empty()){
             ans.push_back(subvector);
             }
         }
         return ans;
    }
};
*/