Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:
        3                        0
    5       1                  -1  1
 6     2   0 8
      7 4
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void build_map(TreeNode* root, unordered_map<int,vector<int>> &map, unordered_map<int,bool>& visited){
        if(!root) return;
        visited[root->val] = false;
        if(root->right){
            map[root->val].push_back(root->right->val);
            map[root->right->val].push_back(root->val);
            build_map(root->right,map,visited);
        }
        if(root->left){
            map[root->val].push_back(root->left->val);
            map[root->left->val].push_back(root->val);
            build_map(root->left,map,visited);
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> map;
        unordered_map<int,bool> visited;
        build_map(root, map, visited);
        if(map.find(target->val) == map.end()) return {};
        deque<int> q;
        q.push_back(target->val);
        visited[target->val] = true;
        int dis=0;
        while(dis < k){
            int n = q.size();
            for(int i=0; i < n; i++){
                int cur = q.front();
                q.pop_front();
                visited[cur] = true;
                for( int next_node:map[cur]){
                    if(!visited[next_node])q.push_back(next_node);
                }
            }
            dis++;
        }
        return {q.begin(),q.end()};
    }
};

[0,1,null,null,2,null,3,null,4]