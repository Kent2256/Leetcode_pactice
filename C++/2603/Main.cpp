There exists an undirected and unrooted tree with n nodes indexed from 0 to n - 1. 
You are given an integer n and a 2D integer array edges of length n - 1,
where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
You are also given an array coins of size n where coins[i] can be either 0 or 1, 
where 1 indicates the presence of a coin in the vertex i.

Initially, you choose to start at any vertex in the tree. 
Then, you can perform the following operations any number of times: 

Collect all the coins that are at a distance of at most 2 from the current vertex, or
Move to any adjacent vertex in the tree.
Find the minimum number of edges you need to go through to collect all the coins and go back to the initial vertex.

Note that if you pass an edge several times, you need to count it into the answer several times.

 

Example 1:


Input: coins = [1,0,0,0,0,1], edges = [[0,1],[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: Start at vertex 2, collect the coin at vertex 0, move to vertex 3, collect the coin at vertex 5 then move back to vertex 2.
Example 2:


Input: coins = [0,0,0,1,1,0,0,1], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[5,6],[5,7]]
Output: 2
Explanation: Start at vertex 0, collect the coins at vertices 4 and 3, move to vertex 2,  collect the coin at vertex 7, then move back to vertex 0.
 

Constraints:

n == coins.length
1 <= n <= 3 * 104
0 <= coins[i] <= 1
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        //check the amount of coins and the position
        vector<vector<int>> coin_neighbor(coins.size());
        for(auto edge:edges){
            coin_neighbor[edge[0]].push_back(edge[1]);
            coin_neighbor[edge[1]].push_back(edge[0]);
        }
        vector<int> coinstack;
        int coin_sum=0;
        for(int i=0;i<coins.size();i++){
            if(coins[i]){
                coinstack.push_back(i);
                coin_sum++;
            }
        }
        if(coinstack.size()==0)return 0;
        int res=0;
        for(int i=0;i<coinstack.size();i++){
            queue<int> q;
            q.push(coinstack[i]);
            q.push(-1);
            vector<bool> visited(coins.size(),true);
            int cur_sum=0;
            int level=0;
            while(!q.empty() && cur_sum<coin_sum){
                int cur=q.front();
                q.pop();
                if(cur==-1){
                    if(q.front()==-1)break;
                    q.push(-1);
                    level++;
                    continue;
                }
                if(coins[cur])cur_sum++;
                visited[cur]=false;
                for(int next:coin_neighbor[cur]){
                    if(visited[next])q.push(next);
                }
            }
            res = max(res,level);
        }
        int res = (res-4)*2;
        return max(res,0);
    }
};

 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
[1,1,1,0,0,0,0,0,1,0,0, 1, 1, 0, 1, 1, 0, 0, 1]

[[0,1],[1,2],[2,3],[1,4],[4,5],[5,6],[6,7],[3,8],[6,9],[7,10],[10,11],[10,12],[7,13],[12,14],[13,15],[14,16],[15,17],[10,18]]
[[5,6],[6,7],[6,9]]


 0         5   7   9     12  14      18
[1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1]
[[0,1],[1,2],[2,3],[3,4],[4,5],[4,6],[5,7],[6,8],[7,9],[9,10],[8,11],[11,12],[12,13],[11,14],[12,15],[12,16],[13,17],[17,18]]



class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        const int count = coins.size();
        if (count <= 2) {
            return 0;
        }
        
         vector< set<int>> s1(count);
        for (auto &&edge : edges) {
            s1[edge[0]].insert(edge[1]);
            s1[edge[1]].insert(edge[0]);
        }
        
         queue<int> next;
        for (int node = 0; node < count; ++node) {
            if (s1[node].size() == 1) {
                next.push(node);
            }
        }
        
         vector<int> dis(count, 0);        
        
        int count1 = 0;
        while (!next.empty()) {
            const int current = next.front();
            next.pop();
            ++count1;
            assert(s1[current].size() <= 1);
            if (s1[current].empty()) {
                continue;
            }
            const int x = *s1[current].begin();
            s1[x].erase(current);
            if (coins[current] == 1) {
                coins[x] = 1;
                dis[x] =  max(dis[current] + 1, dis[x]);
            }
            if (s1[x].size() != 1)  {
                continue;
            }
            if (dis[x] == 2) {
                continue;
            }
            next.push(x);
        }
 
        return  max(count - count1 - 1, 0) * 2; 
    }
};