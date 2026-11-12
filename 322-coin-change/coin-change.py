class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        n = len(coins)
        dp = [[-1 for _ in range(amount+1)] for _ in range(n+1)]
        
        def solve(i, total):
            if total == amount:
                return 0
            if total > amount or i == n:
                return float('inf')
            if dp[i][total] != -1:
                return dp[i][total]

            pick = 1 + solve(i, total + coins[i])
            skip = solve(i + 1, total)

            dp[i][total] = min(pick, skip)
            return dp[i][total]

        ans = solve(0,0)
        return ans if ans != float('inf') else -1
        

        