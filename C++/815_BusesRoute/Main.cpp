You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], 
this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially),
 and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        int len = routes.size();
        unordered_map<int,vector<int>> map;
        int maxStop = -1;
        for( int i=0;i<len;i++){
            for(int stop:routes[i]){
                map[stop].push_back(i);
                maxStop = max(maxStop,stop);
            }
        }
        if(map.find(source) == map.end())return -1;
        vector<bool> visited_stop(maxStop+1,true);
        vector<bool> visited_route(len,true);
        queue<int> q;
        q.push(source);
        visited_stop[source] = false;
        int res=1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n;i++){
                for(int routes_id:map[q.front()]){
                    if(visited_route[routes_id] == false)continue;
                    visited_route[routes_id] = false;
                    for( int stop:routes[routes_id]){
                        if(stop == target)return res;
                        if(visited_stop[stop] == true){
                            q.push(stop);
                            visited_stop[stop] = false;
                        }
                    }
                }
                q.pop();
            }
            res++;
        }
        return -1;
    }
}; 
