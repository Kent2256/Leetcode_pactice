// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course 
// bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
// If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]
// 1 ==> 0 1
// 0 ==> 
// make a hashtable
// 0:1
// 1:2
// 2:0
 

// bool list of path, if failed return empty vector
// bool list of visited
// hash table 
// make a list of course
// reverse the course list and return

class Solution {
public:
    bool bfs(vector<vector<int>>& map, vector<bool>& visited, vector<bool>& path, int i,vector<int>& result){
        if(path[i] == false) return false;
        if(visited[i] == true) return true;
        path[i] = false;
        visited[i] = true;
        for(auto next:map[i]){
            if(!bfs(map,visited,path,next,result))return false;
        }
        path[i] = true;
        result.push_back(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> path(numCourses,true);
        vector<bool> visited(numCourses,false);
        vector<int> result;
        vector<vector<int>> map(numCourses);
        for( auto vec:prerequisites){
            map[vec[0]].push_back(vec[1]);
        }
        for(int i = 0; i<numCourses; i++){
            if (!bfs(map,visited,path,i,result)) return {};
        }
        return result;
    }
};

class Solution {
public:
    vector<int> isNotCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()==V) return topo;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites) adj[it[1]].push_back(it[0]);
        return isNotCyclic(numCourses,adj);
    }
};