322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:
[true,true,true,true,true,true,true,true,true]
[0,1,2,3,4,5,6,7,8,9,10,11]
[0,1,1,2,]
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
[[1,2147483647],2]
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coin_nums[amount+1];
        fill(coin_nums, coin_nums + amount + 1, INT_MAX);
        coin_nums[0]=0;
        for(int i=0; i <= amount; i++){
            if(coin_nums[i] != INT_MAX){ 
                for(int coin:coins){
                    if(coin <= amount && i+coin <= amount){
                        coin_nums[i+coin] = min(coin_nums[i+coin],coin_nums[i] + 1);
                    }
                }
            }
        }
        if(coin_nums[amount] != INT_MAX) return coin_nums[amount];
        else return -1;
    }
};

class Solution {
public:
    vector<int> coins;
    vector<int> memo;

    int minCoins(int amt){
        int i, j, min, val;
        memo[0] = 0;

        for(i = 1; i <= amt; i++){
            min = amt + 1;
            for(j = 0; j < (int)coins.size(); j++){
                if (i >= coins[j]){
                    val = memo[i-coins[j]] + 1;
                    if (val != 0 && val < min) min = val;
                }
            }
            if (min == amt + 1) min = -1;
            memo[i] = min;
        }
        return memo[amt];
    }

    int coinChange(vector<int>& coins, int amount) {
        size_t i;
        this->coins = coins;

        memo.resize(amount+1);

        return minCoins(amount);
    }
};