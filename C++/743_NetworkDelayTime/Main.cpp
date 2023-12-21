You are given a network of n nodes, labeled from 1 to n.
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, 
vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k.
Return the minimum time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> map(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<bool> visited(n+1,false);
        for(vector<int> time:times){
            map[time[0]].push_back({time[2],time[1]});
        }
        for(auto neighbor:map[k]){
            pq.push(neighbor);
        }
        visited[k] = true;
        int step = 0;
        int res = 0;
        while(step<n && !pq.empty()){
            auto [dis,next] = pq.top();
            pq.pop();
            if(visited[next] == true) continue;
            visited[next] = true;
            res = dis;
            for(auto neighbor:map[next]){
                pq.push({neighbor.first + res,neighbor.second});
            }
            step++;
        }
        return step!=n-1?-1:res;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for(auto edge: adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDist = -1;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX)
                return -1;
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};