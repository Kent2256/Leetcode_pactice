Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 4
Example 2:
                [["1","0","1","0","0"],
                 ["1","0","2","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]

Input: matrix = [["0","1"],
                 ["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 [["4","3","2","1","0"],
  ["3","3","2","1","0"],
  ["2","2","3","2","1"],
  ["1","1","2","2","1"],
  ["0","0","1","1","1"]]


  [["1","1","1","1","1","1","1","1"],
   ["1","1","1","1","1","1","1","0"],
   ["2","3","3","2","1","1","1","0"],
   ["1","2","2","2","1","0","0","0"],
   ["0","1","1","1","1","0","0","0"]]

4,5,5,4,3,2,1,1,
3,4,4,3,2,2,1,0,
2,3,3,2,1,1,1,0,
1,2,2,2,1,0,0,0,
0,1,1,1,1,0,0,0,

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n =matrix.size(),m = matrix[0].size();
        vector<vector<int>> matrix_int(n,vector<int>(m,0));
        int res = 0;
        for(int i=n-1; i >=0;i--){
            for(int j=m-1;j >=0;j--){
                if(matrix[i][j] == '1'){
                    if(i==n-1 || j==m-1){
                        matrix_int[i][j] = 1;
                    }
                    else{
                        matrix_int[i][j] = min(matrix_int[i+1][j],min(matrix_int[i+1][j+1],matrix_int[i][j+1])) + 1;
                    }
                    res = max(res , matrix_int[i][j]); 
                }
            }
        }
        return res*res;
    }
};





