// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
//connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int& count){
        int m = grid.size(), n = grid[0].size();
        if(row < 0 || row >= m||col < 0|| col >= n || grid[row][col] != 1) return count;
        grid[row][col] = -1;
        count++;
        dfs(grid,row+1,col,count);
        dfs(grid,row,col+1,count);
        dfs(grid,row-1,col,count);
        dfs(grid,row,col-1,count);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;
        int count = 0;
        for(int i=0;i<m;i++){
            for(int k = 0; k< n; k++){
                if(grid[i][k] == 1){
                    count = 0;
                    max_area = max(max_area, dfs(grid,i,k,count));
                }
            }
        }
        return max_area;
    }
};

int main(){
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    vector<vector<int>> grid2 = {
        {1,1,0,0,0},
        {1,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};

    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
    cout << sol.maxAreaOfIsland(grid2) << endl;
}