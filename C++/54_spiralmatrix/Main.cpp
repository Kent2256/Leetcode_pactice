iven an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
dir: (0,1),(1,0),(0,-1),(-1,0);

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> visited(m,vector<bool>(n,true));
        queue<pair<int,int>> q;
        vector<int> result;
        q.push({0,0});
        int k=0;
        while(!q.empty()){
            auto [col,row] = q.front();
            result.push_back(matrix[col][row]);
            visited[col][row] = false;
            int n_col = col+dir[k][0], n_row=row+dir[k][1];
            if(n_col >= 0 && n_col < m && n_row >= 0 && n_row <n && visited[n_col][n_row] == true){
                q.push({n_col,n_row});
            }
            else{
                k = (k+1)%4;
                n_col = col+dir[k][0], n_row=row+dir[k][1];
                if(n_col >= 0 && n_col < m && n_row >= 0 && n_row <n && visited[n_col][n_row] == true){
                    q.push({n_col,n_row});
                }
            }
            q.pop();
        } 
        return result; 
    }
};