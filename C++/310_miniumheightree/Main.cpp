A tree is an undirected graph in which any two vertices are connected by exactly one path. 
In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] 
indicates that there is an undirected edge between the two nodes ai and bi in the tree, 
you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. 
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:

0=>1
1=>0,2,3
2=>1
3=>1
[1,2,1,1]
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:

0=>3
1=>3
2=>3
3=>0,1,2,4
4=>3,5
5=>4
[1,1,1,4,2,1]
Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.

n^2 ==> n
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> next_layer;
        vector<vector<int>> grid;
        vector<vector<int>> degree;
        vector<bool> visited(n,true;)
        for( vector<int> edge:edges){
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for(int i=0;i<n;i++){
            if(grid[i].size()==1) next_layer.push_back(i);
        }
        vector<int> cur_layer;
        while(!next_layer.empty){
            curr_layer = next_layer;
            next_layer.clear();
            for(int node:curr_layer){
                for(int next:graph[node]){
                    degree[next]--;
                    if(degree[next] == 1){
                        next_layer.push_back(next);
                    }
                }
            }
        }
        return cur_layer;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) graph[i].reserve(16);

        vector<int> degrees(n, 0);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            ++degrees[edge[0]];
            ++degrees[edge[1]];
        }

        vector<int> nextLayer;
        nextLayer.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                nextLayer.push_back(i);
            }
        }

        vector<int> currentLayer;
        currentLayer.reserve(n);
        while (!nextLayer.empty()) {
            swap(currentLayer, nextLayer);
            nextLayer.clear();
            for (int i : currentLayer) {
                for (int j : graph[i]) {
                    if (--degrees[j] == 1) {
                        nextLayer.push_back(j);
                    }
                }
            }
        }

        return currentLayer;
    }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

/*
remove nodes from the graph until there are one or two left
represent graph as a vector of unordered_sets
collect nodes with a single edge
remove them, remove corresponding records from other nodes
if in those nodes the amount of edges == 1, add them to the container
when to stop?
when there are no nodes left, return previous container.
*/