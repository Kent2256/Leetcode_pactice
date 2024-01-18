There is an undirected graph with n nodes, numbered from 0 to n - 1.

You are given a 0-indexed integer array scores of length n where scores[i] denotes the score of node i.
You are also given a 2D integer array edges where edges[i] = [ai, bi] 
denotes that there exists an undirected edge connecting nodes ai and bi.

A node sequence is valid if it meets the following conditions:

There is an edge connecting every pair of adjacent nodes in the sequence.
No node appears more than once in the sequence.
The score of a node sequence is defined as the sum of the scores of the nodes in the sequence.

Return the maximum score of a valid node sequence with a length of 4. If no such sequence exists, return -1.

 

Example 1:


Input: scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 24
Explanation: The figure above shows the graph and the chosen node sequence [0,1,2,3].
The score of the node sequence is 5 + 2 + 9 + 8 = 24.
It can be shown that no other node sequence has a score of more than 24.
Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and have a score of 24.
The sequence [0,3,2,4] is not valid since no edge connects nodes 0 and 3.
Example 2:


Input: scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
Output: -1
Explanation: The figure above shows the graph.
There are no valid node sequences of length 4, so we return -1.
 

Constraints:

n == scores.length
4 <= n <= 5 * 104
1 <= scores[i] <= 108
0 <= edges.length <= 5 * 104
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no duplicate edges.

class Solution {
public:
    int dfs(vector<int>& scores, vector<vector<int>>& map, vector<bool>& visited, int node, int i, int sum){
        sum+=scores[node];
        if(i==4)return sum;
        int res=-1;
        visited[node] = true;
        for(int next_node:map[node]){
            if(!visited[next_node]){
                res = max(res,dfs(scores,map,visited,next_node,i+1,sum));
            }
        }
        visited[node] = false;
        return res;
    }
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        vector<vector<int>> map(scores.size(),vector<int>);
        for(vector<int>& edge:edges){
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(scores.size(),false);
        int result = -1;
        for(int i=0;i<scores.size();i++){
            result = max(result,dfs(scores,map,visited,i,1,0))
        }
        return
    }
};

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        // find the best neighbours (at most 3)
        vector<set<pair<int, int>>> m(n);
        for(auto x : edges) {
            int u = x[0], v = x[1];
            m[u].insert({scores[v], v});
            m[v].insert({scores[u], u});
            if (m[u].size() > 3) m[u].erase(m[u].begin());
            if (m[v].size() > 3) m[v].erase(m[v].begin());
        }
        // iterate each combination to find the answer
        int ans = -1;
        for (auto x : edges) {
            int u = x[0], v = x[1];
            for (auto x1 : m[u]) {
                for (auto x2 : m[v]) {
                    // skip some cases
                    if (x1.second != x2.second && x1.second != v && x2.second != u) {
                        ans = max(ans, scores[u] + scores[v] + x1.first + x2.first);
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        multiset<pair<int, int>> mst[n];  

        for(auto &e: edges) {
            mst[e[0]].insert({scores[e[1]], e[1]});
            mst[e[1]].insert({scores[e[0]], e[0]});

            if(mst[e[0]].size() > 3)    
                mst[e[0]].erase(mst[e[0]].begin());
            if(mst[e[1]].size() > 3)    
                mst[e[1]].erase(mst[e[1]].begin());
        }

        int ans = -1;
        for(auto &e: edges) {
            for(auto &[si, i]: mst[e[0]])
                for(auto &[sj, j]: mst[e[1]])
                    if(i != j && i != e[1] && j != e[0])
                        ans = max(ans, si + sj + scores[e[0]] + scores[e[1]]);
        }

        return ans;
    }
};

[14,12,10,8,1,2,3,1]

[[1,0],[2,0],[3,0],[4,0],[5,1],[6,1],[7,1],[2,1]]