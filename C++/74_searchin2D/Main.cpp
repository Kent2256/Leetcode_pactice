#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        int length=m*n;
        int l= 0, r= length-1;
        int mid;
        while(l <= r){
            mid = (l + r) /2;
            int col = mid/n;
            int row = mid%n;
            if(matrix[col][row] == target)return true;
            else if(matrix[col][row] > target){
                r = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;

    }
};

int main(){
    vector<vector<int>> matrix = {
    {1,3,5,7},
    {10,11,16,20},
    {23,30,34,60}};
    int target = 3;
    Solution sol;
    cout << sol.searchMatrix(matrix,target);
}