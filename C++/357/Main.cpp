Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

 

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
Example 2:

Input: n = 0
Output: 1
 

Constraints:

0 <= n <= 8

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        vector<int> dp(n,0);
        dp[0] = 9;
        int result=10;
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]*(10-i);
            result+=dp[i];
        }
        return result;
    }
};