Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or 
diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],
                [6,5,4],
                [7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

class Solution {
public:
    int falling(vector<vector<int>>& matrix, vector<vector<int>>& result, int i, int j, const int& n){
        if(result[i][j]!=INT_MAX)return result[i][j];
        int min_val =INT_MAX;
        for(int k=-1;k<=1;k++){
            if(i+1>= 0 && i+1 < n && j+k >=0 && j+k < n){
                min_val = min(min_val,falling(matrix,result,i+1,j+k,n));
            }
        }
        result[i][j] = min_val + matrix[i][j];
        return result[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> result(n,vector<int>(n,INT_MAX));
        for(int m=0;m<n;m++)result[n-1][m] = matrix[n-1][m];
        int res = INT_MAX;
        for(int m=0;m<n;m++){
            res = min(res, falling(matrix,result,0,m,n));
        }
        return res;
    }
};