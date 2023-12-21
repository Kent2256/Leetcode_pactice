The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
'
class Solution {
public:
    bool checkvalid(vector<string> sub_res, int n){
        int sum,m,n;
        for( int k =0; k<n;k++){
            sum = 0;
            m=k;n=0;
            while(m < n){
                if(sub_res[m][n] == 'Q')sum++;
                m++;n++;
            }
            if(sum>=2)return false;
        }
        for(int k=1;k<n;k++){
            sum = 0;
            m=0;n=k;
            while(m < n){
                if(sub_res[m][n] == 'Q')sum++;
                m++;n++;
            }
            if(sum>=2)return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> sub_res(n,"");
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(k!=i){
                    sub_res[i] += '.';
                }
                else sub_res[i] += 'Q';
            }
        }

    }
};

class Solution {
public:
   
    void solveNQueensUtil(int n, int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& left,
    vector<int>& principleDiagonal, vector<int>& secondaryDiagonal){
             if(col == n){
                 ans.push_back(board);
                 return;
             }
          
               for(int row = 0; row < n; row++){
                    if(secondaryDiagonal[row + col] == 0 && principleDiagonal[n - 1 + row - col] == 0 &&
                     left[row] == 0){
                        board[row][col] = 'Q';
                        secondaryDiagonal[row + col] = 1;
                        principleDiagonal[n - 1 + row - col] = 1;
                        left[row] = 1;
                        solveNQueensUtil(n, col + 1, board, ans, left, principleDiagonal, secondaryDiagonal);
                        board[row][col] = '.';
                        secondaryDiagonal[row + col] = 0;
                        principleDiagonal[n - 1 + row - col] = 0;
                        left[row] = 0;
                    }
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n, '.');
        vector<string> board(n, str);
        vector<vector<string>> ans;

        vector<int> leftCol(n, 0);
        vector<int> principleDiagonal(2 * n - 1, 0);
        vector<int> secondaryDiagonal(2 * n - 1, 0);
        solveNQueensUtil(n, 0, board, ans, leftCol, principleDiagonal, secondaryDiagonal);
    
        return ans;
    }
};