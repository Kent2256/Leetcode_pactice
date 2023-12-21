You are given an array points representing integer coordinates of some points on a 2D-plane, 
where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
|xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. 
All points are connected if there is exactly one simple path between any two points.

class Solution {
public:
    int distance(vector<int> a, vector<int> b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> map;
        vector<bool> visited(n,false);
        int res=0;
        visited[0] = true;
        for(int i =0;i<points.size()-1;i++){
            for(int k=0; k < points.size();k++){
                if(!visited[k])map.push({distance(points[i],points[k],k});
            }
            auto [dis,index] = map.top();
            while(visited[index])map.pop();
            res+=dis;
            visited[index] = true;
            map.pop();
        }
        return res;
    }
};
