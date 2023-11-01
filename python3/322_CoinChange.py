from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for coin in coins:
            for i in range(coin, amount + 1):
                print(i)
                dp[i] = min(dp[i], dp[i - coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1
       
    
if __name__ == '__main__':
    # coins = [186,419,83,408]
    # amount = 6249
    # print(Solution().coinChange(coins, amount))
    coins = [5,3]
    amount = 9
    print(Solution().coinChange(coins, amount))
    