// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
//The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents 
//the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the 
//neighboring cell's height is less than or equal to the current cell's height. 
//Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) 
//to both the Pacific and Atlantic oceans.

 

// Example 1:
// [
//     [1,2,2,3,5],
//     [3,2,3,4,4],
//     [2,4,5,3,1],
//     [6,7,1,4,5],
//     [5,1,1,2,4]
//     ]

// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean 
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean 
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean 
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int row, int col, int prev){
        int m=heights.size(),n=heights[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || heights[row][col] < prev) return;
        if(ocean[row][col] == 1) return;
        ocean[row][col] = 1;
        dfs(heights,ocean,row+1,col,heights[row][col]);
        dfs(heights,ocean,row,col+1,heights[row][col]);
        dfs(heights,ocean,row-1,col,heights[row][col]);
        dfs(heights,ocean,row,col-1,heights[row][col]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> pacific(m,vector<int>(n,0));
        vector<vector<int>> atlantic(m,vector<int>(n,0));
        vector<vector<int>> result;
        for(int i=0; i < m;i++){
            dfs(heights,pacific,i,0,-1);
            dfs(heights,atlantic,i,n-1,-1);
        }
        for(int i=0; i < n;i++){
            dfs(heights,pacific,0,i,-1);
            dfs(heights,atlantic,m-1,i,-1);
        }
        for(int i =0; i< m;i ++){
            for(int k=0;k<n;k++){
                if(pacific[i][k] && atlantic[i][k]){
                    result.push_back({i,k});
                }
            }
        }
        return result;
    }
};

int main(){
    //vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> heights = {{1}};
    Solution sol;
    vector<vector<int>> res = sol.pacificAtlantic(heights);
    for(auto v1:res){
        cout << "{";
        for(auto v2:v1){
            cout << v2 << ",";
        }
        cout << "}" << endl;
    }
}