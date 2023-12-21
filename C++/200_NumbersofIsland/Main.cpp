// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
//You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col){
        int m = grid.size(), n = grid[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1') return;
        grid[row][col] = -1;
        dfs(grid,row+1,col);
        dfs(grid,row,col+1);
        dfs(grid,row-1,col);
        dfs(grid,row,col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count =0;
        for(int i = 0; i < m; i++){
            for(int k =0; k< n;k++){
                if(grid[i][k] == '1'){
                    dfs(grid,i,k);
                    count++;
                }
            }
        }
        return count;
    }
};