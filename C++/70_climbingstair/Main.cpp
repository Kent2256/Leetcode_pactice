#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {// 1<= n <=45
    if (n==1){
        return 1;
    }
    int *res_list = new int[n + 1];
    res_list[0] = 1;
    res_list[1] = 1;
    for( int i = 2; i<= n ; i++){
        res_list[i] = res_list[i-1] + res_list[i-2];
    }
    return res_list[n];
    }
};
/*
class Solution {
public:
    int climbStairs(int n, unordered_map<int, int>& memo) {
        // base case
        if (n == 1 || n == 0) {
            return 1;
        }

        if (memo.find(n) == memo.end()) {
            memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
        }

        return memo[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> memo;
        
        return climbStairs(n, memo);
    }
};*/

int main(){
    int n = 1, n2=3;
    Solution sol;
    cout << sol.climbStairs(n) << endl;
    cout << sol.climbStairs(n2) << endl;
}