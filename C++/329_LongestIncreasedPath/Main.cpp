Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],
                [6,6,8],
                [2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1

class Solution {
public:
    int DFS(int col, int row, vector<vector<int>> &cache,vector<vector<int>>& matrix){
        if(cache[col][row] != -1) return cache[i][j];
        int res=1;
        int[] dir_c = {1,0,-1,0};
        int[] dir_r = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nc = col+dir_c[i] , nr = row+dir_r[i];
            if( nc < matrix.size() && nc >=0 && nr < matrix[0].size() && nr >=0 && matrix[col][row] < matrix[nc][nr]){
                res = max(res,1+DFS(nc,nr,cache,matrix));
            }
        }
        cache[col][row] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int>> cache(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max (res,DFS(i,j,cache,matrix));
            }
        }
        return res;
    }
};