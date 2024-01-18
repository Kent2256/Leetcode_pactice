You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. 
You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
Buy wait sell
Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
    }
};

class Solution {
public:
  int solve(int i, vector<int>&prices,int l,int k,vector<vector<int>>&dp)
    {
        if(i==prices.size()||l==2*k)
           return 0;
        if(dp[i][l]!=-1)
           return dp[i][l];
        int profit=0;
        if(l%2==0)
        {
            int Buy=(-prices[i]+solve(i+1,prices,l+1,k,dp));
            int skip=0+solve(i+1,prices,l,k,dp);
            profit=max(Buy,skip);
        }
        else
        {
            int Sell=(prices[i]+solve(i+1,prices,l+1,k,dp));
            int skip=0+solve(i+1,prices,l,k,dp);
            profit=max(Sell,skip);
        }
        return dp[i][l]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k,-1));
        return solve(0,prices,0,k,dp);
    }
};

[2,4,1]
2,-1,-1,-1,
0, 4,-1,-1,
0, 1, 0,-1,

[3,2,6,5,0,3]
7,-1,-1,-1,
7,9,-1,-1,
3,9,3,-1,
3,8,3,5,
3,3,3,3,
0,3,0,3,
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        int dp[n];
        for(int j=0;j<n;j++)
        {
                dp[j]=0;
        }

        for(int i=1;i<=k;i++)
        {
            int mx=-prices[0];
            for(int j=1;j<n;j++)
            {
                /*dp[i][j]=max(dp[i][j-1],prices[j]+mx);
                mx=max(mx,dp[i-1][j]-prices[j]);*/
                mx=max(mx,dp[j]-prices[j]);
                dp[j]=max(dp[j-1],prices[j]+mx);
            }
        }
       return dp[n-1];
        
    }
};