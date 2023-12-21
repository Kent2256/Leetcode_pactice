You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t.
You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        vector<vector<bool>> visited(n,vector(n,false));
        int rain=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        vector<int> dc = {-1,1,0,0};
        vector<int> dr = {0,0,-1,1};
        while(!pq.empty()){
            auto [water,location] = pq.top();
            int col = location.first;
            int row = location.second;
            pq.pop();
            cout << "{" << col << "," <<row<< "}";
            if(visited[col][row] == true)continue;
            visited[col][row] = true;
            rain = max(rain,water);
            if(col==row==n-1) return rain;
            for(int i=0;i<4;i++){
                if( col+dc[i] >= 0 && col+dc[i] < n && row+dr[i] >=0 && row+dr[i] < n && visited[col+dc[i]][row+dr[i]] == false){
                    pq.push({grid[col+dc[i]][row+dr[i]],{col+dc[i],row+dr[i]}});
                }
            }
        }
        return rain;
    }
};


class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& heightGrid) {
        int size = heightGrid.size();
        int lowerBound = heightGrid[0][0], upperBound = size * size - 1;
        
        while (lowerBound < upperBound) {
            int mid = lowerBound + (upperBound - lowerBound) / 2;
            if (isPathValid(heightGrid, mid))
                upperBound = mid;
            else
                lowerBound = mid + 1;
        }
        
        return lowerBound;
    }

private:
    bool isPathValid(std::vector<std::vector<int>>& heightGrid, int waterHeight) {
        int size = heightGrid.size();
        std::vector<std::vector<int>> visited(size, std::vector<int>(size, 0));
        std::vector<int> direction({-1, 0, 1, 0, -1});
        return dfs(heightGrid, visited, direction, waterHeight, 0, 0, size);
    }

    bool dfs(std::vector<std::vector<int>>& heightGrid, std::vector<std::vector<int>>& visited, 
             std::vector<int>& direction, int waterHeight, int row, int col, int size) {
        visited[row][col] = 1;

        for (int i = 0; i < 4; ++i) {
            int newRow = row + direction[i];
            int newCol = col + direction[i + 1];

            if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size &&
                visited[newRow][newCol] == 0 && heightGrid[newRow][newCol] <= waterHeight) {
                if (newRow == size - 1 && newCol == size - 1) 
                    return true;
                if (dfs(heightGrid, visited, direction, waterHeight, newRow, newCol, size)) 
                    return true;
            }
        }
        
        return false;
    }
};