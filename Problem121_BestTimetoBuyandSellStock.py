from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sum=0
        max_profit=0
        for i in range(len(prices)-1):
            prices[i] = prices[i+1]-prices[i]
            sum = max(prices[i], sum+prices[i])
            max_profit = max(sum, max_profit)
        return max_profit
    
prices = [7,1,5,3,6,4]
solve = Solution()
print(solve.maxProfit(prices))