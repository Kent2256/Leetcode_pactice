Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int[201] col;
        int[201] row;
        for(int i=0;i<m;i++){
            for(int k=0;k<n;k++){
                if(matrix[i][k]==0){
                    col[i]=0;
                    row[k]=0;
                }
                else{
                    col[i]=1;
                    row[k]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int k=0;k<n;k++){
                if(col[i]==0 || row[k] ==0)matrix[i][k]=0;
            }
        }
    }
};