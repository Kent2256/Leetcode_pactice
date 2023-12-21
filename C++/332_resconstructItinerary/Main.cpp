You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.


class Solution {
public:
    void DFS(auto &map,string curr, vector<string>&res){
        if(map[curr].empty()){
            res.push_back(curr);
            return;
        }
        while(!map[curr].empty()){
            string next = map[curr].top();
            map[curr].pop();
            DFS(map,next,res);
        }
        res.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> map;
        vector<string> res;
        for(auto sta:tickets){
            map[sta[0]].push(sta[1]);
        }
        string curr = "JFK";
        DFS(map,curr,res);
        reverse(res.begin(),res.end());
        return res;
    }
};


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> graph;
        
        for(int i=0; i<tickets.size(); i++){
            graph[tickets[i][0]].insert(tickets[i][1]);
        }
        
        stack<string> s;
        s.push("JFK");
        
        vector<string> ans;
        
        while(!s.empty()){
            string src = s.top();
            if(graph[src].size() == 0){
                ans.push_back(src);
                s.pop();
            }
            else{
                auto dst = graph[src].begin();
                s.push(*dst);
                graph[src].erase(dst);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};